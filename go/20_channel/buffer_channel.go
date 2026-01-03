package main

import (
	"fmt"
	"time"
)

func sendEmail(email chan<- string, address string) {
	email <- address
}

func emailSender(email <-chan string, done chan<- bool, id int) {
	defer func() { done <- true }()

	for emailAddress := range email {
		println("Sending email to:", emailAddress, " by sender ", id)
		// Simulate email sending process
		time.Sleep(500 * time.Millisecond)
	}
}


func main() {
	emailChannel := make(chan string, 20)
	done := make(chan bool)

	// go emailSender(emailChannel, done, 1)
	// go emailSender(emailChannel, done, 2)
	// for emailSender()
	start := time.Now()
	for i := 1; i <= 10; i++ {
		go emailSender(emailChannel, done, i)
	}

	// _ = start
	for i:= range 100 {
	// emailAddress := "user" +  + "@example.com"
		// go sendEmail(email, emailAddress)
		// emailChannel := strings.Join([]string{"user", string(i), "@example.com"}, "")
		// go sendEmail(email, emailChannel)
		fmt.Println("sending",i)
		emailChannel <- fmt.Sprintf("User%d@gmail.com", i)
		fmt.Println("sent",i)
	}

	// in case of buffered channel we need to close the channel to notify all the go routines that no more data will be sent on this channel
	// so that they can exit the for range loop
	close(emailChannel)
	<-done
	endTime := time.Now()

	fmt.Println("Total time taken:", endTime.Sub(start))

	
}
