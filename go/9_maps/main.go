package main

import (
	"fmt"
	"maps"
)

func main(){
	m := make(map[string]int)
	m["one"] = 1
	m["two"] = 2
	m["three"] = 3

	fmt.Println(m)

	delete(m, "two")

	fmt.Println(m)

	value, exists := m["three"]
	if exists {
		fmt.Println("Key 'three' exists with value:", value)
	} else {
		fmt.Println("Key 'three' does not exist")
	}

	// if key does not exist, zero value of the value type is returned
	nonExistentValue := m["four"]
	fmt.Println("Value for non-existent key 'four':", nonExistentValue)

	// len function to get the number of key-value pairs in the map
	fmt.Println("Number of key-value pairs in the map:", len(m))

	// clr
	clear(m);

	mp := map[string]int{"a": 1, "b": 2, "c": 3}
	fmt.Println("Map literal:", mp) 

	fmt.Println("Iterating over map:")
	for key, value := range mp {
		fmt.Printf("Key: %s, Value: %d\n", key, value)
	}

	fmt.Println(maps.Equal(mp,m))


}
