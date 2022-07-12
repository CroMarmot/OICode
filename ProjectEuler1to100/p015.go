package main

import (
  "fmt"
)

func res() int {
  arr := make([][]int,21,21)
  for i:=0;i<21;i++{
    arr[i] = make([]int,21,21)
  }

  for i:=0;i<21;i++{
    arr[i][0] = 1
    arr[0][i] = 1
  }

  for i:=1;i<21;i++{
    for j:=1;j<21;j++{
      arr[i][j] = arr[i-1][j] + arr[i][j-1]
    }
  }
  return arr[20][20]
}

func main() {
  fmt.Println(res())
}
