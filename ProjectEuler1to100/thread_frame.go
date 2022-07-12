package main

import (
    "fmt"
    "sync"
)

func f(wg sync.WaitGroup,cnt int, idx int, c chan int64) {
    fmt.Println( "from :", idx)
    c <- int64(idx)*int64(idx)
}

func main() {
  var wg sync.WaitGroup
  var routineCnt = 8
  wg.Add(routineCnt)
  c := make(chan int64)
  for i:=0;i<routineCnt;i++ {
    go f(wg,routineCnt,i,c)
  }
  var ret int64 = 0
  for i:=0; i<routineCnt;i++{
    var rcv = <-c
    fmt.Println(rcv);
    ret += rcv
  }
  fmt.Println("done", ret)
}
