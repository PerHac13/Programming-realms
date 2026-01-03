package main

func main() {
	
	i:= 3;

	switch i {
	case 1:
		println("one")
	case 2:
		println("two")
	case 3:
		println("three")
	default:
		println("other")
	}

	// multiple conditions in one case

	switch i {
	case 1, 3, 5, 7, 9:
		println("odd")
	case 2, 4, 6, 8, 10:
		println("even")
	default:
		println("other")
	}

	// type switch
	whoAmI := func(i interface{}) {
		switch v := i.(type) {
		case int:
			println("I'm an int:", v)
		case string:
			println("I'm a string:", v)
		default:
			println("Unknown type")
		}
	}

	whoAmI(42)
	whoAmI("hello")
	whoAmI(3.14)
}