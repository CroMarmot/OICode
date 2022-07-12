package main

import (
	"fmt"
	"sync"
)

const vmax = 1000

var ans int = 0

var wg sync.WaitGroup
var mux sync.Mutex
var ch chan int = make(chan int)

func gen(v int, m int) {
	defer wg.Done()
	for i := v; i < vmax; i += v {
		wg.Add(1)
		ch <- i * m
	}
}

func getans() {
	for v := range ch {
		mux.Lock()
		ans += v
		mux.Unlock()
		wg.Done()
	}
}

func main() {
	wg.Add(3)
	go gen(3, 1)
	go gen(5, 1)
	go gen(15, -1)
	go getans()
	wg.Wait()
	fmt.Println(ans)
}
