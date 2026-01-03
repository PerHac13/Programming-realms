package main

import (
	"fmt"
	"time"
)

func task (id int) {
	// Basic task simulation
	fmt.Println("Task", id, "is running")
}

func main() {
	for i := range 25 {
		go task(i) // non blocking call

		go func (id int) { // inline goroutine
			// Anonymous function to demonstrate closure
			fmt.Println("Anonymous function for task", id)
		}(i);
	}

	// wait for some time to prevent main from exiting
	time.Sleep(5 * time.Second)

}