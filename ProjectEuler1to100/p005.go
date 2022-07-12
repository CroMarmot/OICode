package main

import (
	"fmt"
)

func gcd(a int, b int) int {
	if a == 0 {
		return b
	} else {
		return gcd(b%a, a)
	}
}

func main() {
	ans := 1
	for i := 1; i <= 20; i++ {
		ans = ans * i / gcd(ans, i)
	}

	fmt.Println(ans)
}
