package main

func add(a int, b int) int {
	return a + b
}

func getLanguage() (string, string) {
	return "Go", "Golang"
}

func  processIt(fn func(a int) int){
	fn(10);
}

func paramRest(a int, rest ...int) {
	println("First:", a)
	for _, v := range rest {
		println("Rest:", v)
	}
}

func processReturn() func(a int) int {
	return func(a int) int {
		println("Inside returned function with:", a)
		return a * 3
	}
}


func main() {

	sum := add(3, 5)
	lang1, lang2 := getLanguage()

	println("Sum:", sum)
	println("Languages:", lang1, "and", lang2)

	fn:= func (a int) int {
		println("Processing:", a)
		return a * 2
	}
	processIt(fn)

	fn1 := processReturn()

	fn1(7)

}
