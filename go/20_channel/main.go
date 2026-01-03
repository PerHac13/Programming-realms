package buffer_channel

import (
	"fmt"
	"math/rand"
	"time"
)

/*
* This code demonstrates a simple use of channels in Go.
* Channels are used for communication between goroutines.
* read and write operations on channels are blocking by default.
 */

func processNum(numberChannel chan int) {
	for {

		fmt.Println("processing number", <-numberChannel)
		time.Sleep(500 * time.Millisecond)
	}
}

func main2() {
	// messageChannel := make(chan string)

	// messageChannel <- "Hello, Channel!" // block here, no goroutine to receive
	// msg := <-messageChannel // this line will never be reached
	// fmt.Println(msg)

	numberChannel := make(chan int)

	go processNum(numberChannel)

	for {
		numberChannel <- rand.Intn(100)
	}



}
