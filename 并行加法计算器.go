//go:build ignore

package main

import (
	"fmt"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
	"sync"
	"time"
)

var mu sync.Mutex
var res int

func add(s int) {
	for i := s; i < s+100; i++ {
		mu.Lock()
		res += i
		mu.Unlock()
	}
}
func main() {
	for i := 0; i < 1000; i++ {
		go add(1 + i*100)
	}
	time.Sleep(time.Second * 5)
	fmt.Println(res)
}
