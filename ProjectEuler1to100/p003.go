package main

import (
	"fmt"
)

const maxi = 1000000

var testv = 600851475143

func main() {
	notprime := make([]bool, maxi)
	for i := 2; i < maxi; i++ {
		if !notprime[i] {
			for j := 2; i*j < maxi; j++ {
				notprime[i*j] = true
			}
			for testv%i == 0 {
				fmt.Println(i)
				testv = testv / i
			}
		}
	}

	fmt.Println(testv)
}
