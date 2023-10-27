package main

import "fmt"

func main() {
	arr := [6]int{10, 20, 30, 40, 50, 60}

	myslice := arr[1:4]

	fmt.Println(myslice)
}
