package main

import (
	"fmt"
)

func main() {
	ans := int64(0)
	var a, b int64 = 1, 2
	for a < 4000000 {
		if a%2 == 0 {
			ans = ans + a
		}
		a, b = b, a+b
	}
	fmt.Println(ans)
}
