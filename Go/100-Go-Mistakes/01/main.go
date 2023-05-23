package main

import "fmt"

func main() {
	t := 100
	if true {
		t := 2
		fmt.Println(t)
		// Prints 2
	}
	fmt.Println(t)
	// Prints 100
}
