package main

import (
	"fmt"

	"gt.com/pH/go/auth"
)

func main() {

	authenticated := auth.Authenticate("admin", "secret")
	if authenticated {
		fmt.Println("User authenticated successfully.")
		authorized := auth.Authorize("admin", "dashboard")
		if authorized {
			fmt.Println("User authorized to access the resource.")
		} else {
			fmt.Println("User not authorized to access the resource.")
		}
	} else {
		fmt.Println("Authentication failed.")
	}

}
