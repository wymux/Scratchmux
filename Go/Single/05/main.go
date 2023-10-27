package main

import "fmt"

func main() {
	s := []int{1, 2, 3, 4, 5}
	t := s[1:4]
	t[0] = 10
	fmt.Println(s[1])
}
