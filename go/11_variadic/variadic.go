package variadic

func ParamRest(a int, rest ...int) {
	println("First:", a)
	for _, v := range rest {
		println("Rest:", v)
	}
}

func sum(numbers ...int) int {
	total := 0
	for _, num := range numbers {
		total += num
	}
	return total
}

func main() {
	ParamRest(1, 2, 3, 4, 5)	

	total := sum(10, 20, 30, 40)
	println("Total Sum:", total)

	numbers := []int{5, 15, 25}
	totalFromSlice := sum(numbers...)
	println("Total Sum from slice:", totalFromSlice)
}