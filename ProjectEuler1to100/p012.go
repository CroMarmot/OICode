package main

import (
  "fmt"
)

func res() int {
  const TESTMAX = 100000
  yzr := make([]int,TESTMAX)
  yzp := make([]int,TESTMAX)
  zs := make([]int,TESTMAX)
  yzr[1] = 1
  yzp[1] = 1

  for i:=2;i<TESTMAX;i++{
    if zs[i] == 0 {
      for j:=i*i;j<TESTMAX;j+=i{
        zs[j] = i
      }
      zs[i] = 1
    }
  }
  for k:=2; k < TESTMAX;k++{
    if zs[k] == 1 {
      yzr[k] = 2
      yzp[k] = 2
    }else{
      yzcnt := 0
      v := k
      for v % zs[k] == 0 {
        yzcnt++
        v/=zs[k]
      }
      yzr[k] = yzr[v] * (1+yzcnt)
    }
    if k % 2 == 1 {
      yzp[k] = yzr[k]
    }else{
      yzp[k] = yzr[k/2]
    }
  }
  for k:=1;k<TESTMAX-1;k++{
    // fmt.Printf("k=%v,yzr=%v,yzp=%v\n",k,yzr[k],yzp[k])
    if yzp[k]*yzp[k+1] >= 500 {
      return k*(k+1)/2
    }
  }
  return 0
}

func main() {
  fmt.Println(res())
}
