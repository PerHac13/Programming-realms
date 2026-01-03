package main

func secondary() {
	println("This is a secondary function.")
}

func main() {

	age := 20
	
	if age < 18 {
		println("Minor")
	} else {
		println("Adult")
	}

	if par:= age % 2; par == 0 {
		println("Even age")
	} else {
		println("Odd age")
	}

	secondary()

	// no ternary operator in Go

	
	
}