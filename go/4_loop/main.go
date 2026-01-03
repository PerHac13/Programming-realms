package main

/*
* for : only construct in go for looping
 */

func main() {
	
	// while loop

	i:=1

	for i<=5 {
		println("Value of i:", i)
		i++
	}

	// infinite loop
	
	/*
	for {
		println("Infinite Loop")
	}
	*/

	// for loop with initialization, condition, post statement
	for j:=1; j<=5; j++ {
		println("Value of j using traditional loop:", j)
	}

	// break statement
	for k:=1; k<=10; k++ {
		if k==6 {
			println("Breaking the loop at k =", k)
			break
		}
		println("Value of k:", k)
	}

	// continue statement
	for m:=1; m<=5; m++ {
		if m%2 == 0 {
			println("Skipping even number m =", m)
			continue
		}
		println("Value of m:", m)
	}

	// nested loops
	for a:=1; a<=3; a++ {
		for b:=1; b<=2; b++ {
			println("a:", a, "b:", b)
		}
	}

	// range
	for i:= range 3 {
		println("Range value i:", i)
	}
}