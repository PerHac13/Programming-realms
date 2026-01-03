package arrays


func array() {	
	// Declare and initialize an array of integers
	var arr [5]int = [5]int{10, 20, 30, 40, 50}

	var num [6]int

	println("Length of arr:", len(num))

	// Access and print elements of the array
	for i := 0; i < len(arr); i++ {
		println("Element at index", i, "is", arr[i])
	}

	// Modify an element in the array
	arr[2] = 99
	println("After modification, element at index 2 is", arr[2])

	// Declare and initialize an array of strings
	var strArr = [3]string{"Go", "is", "fun"}

	// Print elements of the string array
	for i, v := range strArr {
		println("Element at index", i, "is", v)
	}

	// 2D array
	var matrix [2][3]int = [2][3]int{
		{1, 2, 3},
		{4, 5, 6},
	}

	println("2D Array elements:")
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			println("Element at (", i, ",", j, ") is", matrix[i][j])
		}
	}

	// 2D array using range
	println("2D Array elements using range:")
	for i, row := range matrix {
		for j, val := range row {
			println("Element at (", i, ",", j, ") is", val)
		}
	}


}