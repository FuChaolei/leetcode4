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
)

var wg sync.WaitGroup
var ca chan int
var cb chan int

func p1() {
	for i := 9; i > 0; i-- {
		ca <- 1
		if i%2 == 1 {
			fmt.Println(i)
		}
	}
	wg.Done()
}
func p2() {
	for i := 9; i > 0; i-- {
		<-ca
		if i%2 == 0 {
			fmt.Println(i)
		}
	}
	wg.Done()
}
func main() {
	ca = make(chan int)
	wg.Add(2)
	go p1()
	go p2()
	wg.Wait()
}
