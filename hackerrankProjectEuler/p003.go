package main

import (
  "fmt"
)

const maxi = int64(1000000)

func max(x, y int64) int64 {
    if x > y {
        return x
    }
    return y
}

func main() {
  notprime := make([]bool, maxi + 10)
  for i := int64(2); i < maxi; i++ {
    if !notprime[i] {
      for j := i; i*j <= maxi; j++ {
        notprime[i*j] = true
      }
    }
  }
  var t int
  fmt.Scanf("%d", &t)
  for ;t>0;t--{
    var n int64
    fmt.Scanf("%d", &n)
    maxp := int64(1)
    for i := int64(2);i < maxi ;i++ {
      if i * i > n {
        break
      }
      if notprime[i] {
        continue
      }
      if n % i == 0 {
        maxp = max(maxp, i);
        for n % i == 0 {
          n /= i
        }
      }
    }
    if n != 1 {
      maxp = max(maxp, n);
    }
    fmt.Println(maxp)
  }
}
