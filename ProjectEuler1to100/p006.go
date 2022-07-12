package main

import (
	"fmt"
)

func res(v int) int {
	l := v * (v + 1) / 2
	r := v * (v + 1) * (2*v + 1) / 6
	return l*l - r
}

func main() {
	fmt.Println(res(100))
}
