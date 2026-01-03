package main

import "sync"

/*
* WaitGroup is used to wait for a collection of goroutines to finish.
* The main goroutine calls Add to set the number of goroutines to wait for.
* Then each of the goroutines runs and calls Done when finished.
* At the same time, Wait can be used to block until all goroutines have finished.
 */

func task(id int, wg *sync.WaitGroup) {
	defer wg.Done()
	println("Task", id, "is running")
}


func main() {
	var wg sync.WaitGroup

	for i:= range 15 {
		wg.Add(1)
		task(i, &wg)
	}

	wg.Wait()
	println("All tasks completed")
	
}