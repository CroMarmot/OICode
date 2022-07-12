package main

import (
	"fmt"
)

func res() int {
	for a := 1; a <= 333; a++ {
		for b := a + 1; b < 1000-a-b; b++ {
			c := 1000 - a - b
			if a*a+b*b == c*c {
				return a * b * c
			}
		}
	}
	return 0
}

func main() {
	fmt.Println(res())
}
