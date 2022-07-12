package main

import (
	"fmt"
)

func res() int {
	ans := 0
	arr := make([]bool, 2000001, 2000001)
	for i := 2; i < 2000000; i++ {
		if !arr[i] {
			ans += i
			for j := i; j <= 2000000/i; j++ {
				arr[i*j] = true
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(res())
}
