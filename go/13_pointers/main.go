package main

func changeValue(val *int) {
	*val = 42
}


func main() {

	num := 10
	println("Before:", num) // Before: 10

	changeValue(&num)

	println("After:", num) // After: 42
}
