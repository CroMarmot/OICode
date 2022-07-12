package main

import (
  "fmt"
)

var (
  times = make(map[int]int)
)

func getv(v int) int {
  nextv := 0
  if v%2 == 0 {
    nextv = v/2
  }else{
    nextv = v*3+1
  }
  if _,ok := times[v]; !ok {
    times[v] = getv(nextv)+1
  }
  return times[v]
}

func res() int {
  times[1] = 1
  maxlen := 1
  ans := 1
  for i := 1;i<=1000000;i++ {
    if i%2 == 0{
      times[i] = times[i/2]+1
      if times[i] > maxlen {
        maxlen = times[i]
        ans = i
      }
      continue
    }
    getv(i)
    if times[i] > maxlen{
      maxlen = times[i]
      ans = i
    }
  }
  return ans
}

func main() {
  fmt.Println(res())
}
