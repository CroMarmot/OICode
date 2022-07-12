package main

import (
	"fmt"
)

func q(v int64,n int64) int64 {
  return (v+(n/v)*v)*(n/v)/2
}

func main() {
  var t int
  fmt.Scanf("%d", &t)
  for t > 0 {
    var n int64
    fmt.Scanf("%d", &n)
    n --;
    var ans int64 = q(3,n) + q(5,n) -q(15,n)
    fmt.Println(ans)
    t--;
  }
}
