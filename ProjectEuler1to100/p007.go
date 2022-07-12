package main

import (
	"fmt"
)

func res(idx int) int {
	arr := make([]bool, 1000000, 1000000)
	cnt := 0
	for i := 2; cnt < idx; i++ {
		if !arr[i] {
			cnt++
			for j := i; j < 1000000/i; j++ {
				arr[i*j] = true
			}
			if cnt == idx {
				return i
			}
		}
	}
	return -1
}

func main() {
	fmt.Println(res(10001))
}
