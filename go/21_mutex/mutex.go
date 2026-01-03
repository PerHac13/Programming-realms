package main

import (
	"sync"
	"time"
)

type post struct {
	views int
	mu sync.Mutex
}

func (p *post) View(wg *sync.WaitGroup) {
	defer func ()  {
		wg.Done()
		p.mu.Unlock()	
	}()
	time.Sleep(5* time.Second)
	p.mu.Lock()
	p.views++
	// p.mu.Unlock()
}

func (p *post) Views() int {
	return p.views
}

func NewPost() *post {
	return &post{}
}

func main() {
	wg := sync.WaitGroup{}
	p := NewPost()
	
	start := time.Now()
	defer func() {
		println("Time taken:", time.Since(start).String())
	}()
	for range 10000 {
		wg.Add(1)
		go p.View(&wg)
	}
	wg.Wait()

	println("Views:", p.Views())
}