package main

import "fmt"


func PrintSlice[T any](s []T) {
	for _, v := range s {
		fmt.Println(v)
	}
}

// scope of T is limited to PrintSliceLimit function

func PrintSliceLimit[T int | string | bool](s []T) {
	for _, v := range s {
		fmt.Println(v)
	}
}

// scope of T for comparable types

func FindIndex[T comparable](s []T, target T) int {
	for i, v := range s {
		if v == target {
			return i
		}
	}
	return -1
}

// struct with generic type
type Box[T any] struct {
	value T
}

func (b Box[T]) GetValue() T {
	return b.value
}

func main() {
	intSlice := []int{1, 2, 3, 4, 5}
	stringSlice := []string{"hello", "world"}

	fmt.Println("Integer Slice:")
	PrintSlice(intSlice)

	fmt.Println("String Slice:")
	PrintSlice(stringSlice)

	myBox := Box[int]{value: 42}
	fmt.Println("Box Value:", myBox.GetValue())
}
