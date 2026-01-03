package main


func getCounter() func() int {
	counter := 0

	return func() int {
		counter++
		return counter
	}
}

func main() {
	counterA := getCounter()
	counterB := getCounter()

	println(counterA()) // 1
	println(counterA()) // 2
	println(counterB()) // 1
	println(counterA()) // 3
	println(counterB()) // 2

	counterA() // 4
	counterA() // 5
	counterB() // 3

	println(counterA()) // 6
	println(counterB()) // 4


}