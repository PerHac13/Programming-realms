package main

import "fmt"

// global declaration
var globalVar string = "I am a global variable"
const globalConst int = 100

const (
	Monday    = "Monday"
	Tuesday   = "Tuesday"
	Wednesday = "Wednesday"
)

func main() {
	fmt.Println("Varaible!")

	var firstName string = "John"

	// infer type
	var lastName = "Doe"

	fmt.Println("Full Name:", firstName, lastName)

	var age int = 30
	fmt.Println("Age:", age)

	// short declaration
	country := "USA"
	fmt.Println("Country:", country)

	year := 2024
	fmt.Println("Year:", year)

	// multiple variable declaration
	var city, state string = "New York", "NY"
	fmt.Println("City:", city, "State:", state)

	// zero value
	var isEmployed bool
	fmt.Println("Is Employed:", isEmployed)

	// constant
	const pi = 3.14
	fmt.Println("Value of Pi:", pi)

	


}