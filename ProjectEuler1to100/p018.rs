#![allow(unused_imports)]
use std::cmp::*;
use std::collections::*;

struct Scanner {
   buffer : std::collections::VecDeque<String>
}

impl Scanner {

   fn new() -> Scanner {
      Scanner {
         buffer: std::collections::VecDeque::new()
      }
   }

   fn next<T : std::str::FromStr >(&mut self) -> T {

      if self.buffer.len() == 0 {
         let mut input = String::new();
         std::io::stdin().read_line(&mut input).ok();
         for word in input.split_whitespace() {
            self.buffer.push_back(word.to_string())
         }
      }

      let front = self.buffer.pop_front().unwrap();
      front.parse::<T>().ok().unwrap()
   }
}

fn main() {
    let mut s = Scanner::new();
    let n : usize = s.next(); // 15
    let mut arr = Vec::new();
    for i in 0..n{
        let mut row = Vec::new();
        for j in 0..i+1{
            let val : usize = s.next();
            row.push(val);
        }
        arr.push(row);
    }
    for i in (0..n-1).rev(){
        for j in 0..i+1{
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }
    println!("{}",arr[0][0]);
}

// rustc ./p018.rs && time cat p018_in  | ./p018
