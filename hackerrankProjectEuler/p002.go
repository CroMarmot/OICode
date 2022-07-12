package main

import (
  "fmt"
)

func f() {
  ans := int64(0)
  var n int64
  fmt.Scanf("%d", &n)
  var a, b int64 = 1, 2
  for a < n {
    if a%2 == 0 {
      ans = ans + a
    }
    a, b = b, a+b
  }
  fmt.Println(ans)
}

func main() {
  var t int
  fmt.Scanf("%d", &t)
  for ;t>0;t--{
    f()
  }
}
