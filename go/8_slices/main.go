package main

import (
	"fmt"
	"slices"
)

func main() {
	var nums []int
	fmt.Println(nums==nil) // true

	nums = []int{}
	fmt.Println(nums==nil) // false

	nums = append(nums, 1, 2, 3)
	fmt.Println(nums) // [1 2 3]

	nums = append(nums, 4, 5)
	fmt.Println(nums) // [1 2 3 4 5]

	var letters = make([]string, 2)
	letters[0] = "a"
	letters[1] = "b"
	fmt.Println(letters) // [a b]

	letters = append(letters, "c", "d")
	fmt.Println(letters) // [a b c d]

	// slice operator

	var nums2 = []int{10, 20, 30, 40, 50}
	fmt.Println(nums2[1:4]) // [20 30 40]
	fmt.Println(nums2[:3])  // [10 20 30]
	fmt.Println(nums2[2:])  // [30 40 50]
	fmt.Println(nums2[:])   // [10 20 30 40 50]
	fmt.Println(nums2[3])


	// slices pkg

	var c1 = []int{1, 2, 3}
	var c2 = []int{4, 5, 6, 7, 8}

	copy(c2, c1)
	fmt.Println(c2) // [1 2 3 7 8]

	fmt.Println(slices.Equal(nums,c2));

	// 2D slices
	var matrix = [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	fmt.Println(matrix[1])	// [4 5 6]
	fmt.Println(matrix[1][2]) // 6

	// slice operations
	var data = []int{5, 10, 15, 20, 25}
	data = slices.Delete(data, 1, 3) // remove elements at index 1 and 2
	fmt.Println(data) // [5 20 25]

	data = slices.Insert(data, 1, 12, 14) // insert 12 and 14 at index 1
	fmt.Println(data) // [5 12 14 20 25]		

	

}