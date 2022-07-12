package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup
var mux sync.Mutex
var ch chan int

var ans = 0

func check(v int) {
	defer wg.Done()
	reversev := 0
	tempv := v
	for tempv != 0 {
		reversev = reversev*10 + tempv%10
		tempv = tempv / 10
	}
	if reversev == v {
		wg.Add(1)
		ch <- v
	}
}

func recvans() {
	for v := range ch {
		mux.Lock()
		if v > ans {
			ans = v
		}
		mux.Unlock()
		wg.Done()
	}
}

func main() {
	ch = make(chan int)
	for i := 100; i < 1000; i++ {
		for j := 100; j < 1000; j++ {
			wg.Add(1)
			go check(i * j)
		}
	}
	go recvans()
	wg.Wait()
	fmt.Println(ans)
}
