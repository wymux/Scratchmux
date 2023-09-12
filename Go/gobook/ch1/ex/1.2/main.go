package main

import (
	"fmt"
	"os"
)

func main() {
	for i, _ := range os.Args[0:] {
		fmt.Fprintf(os.Stdout, "%d: %s\n", i, os.Args[i])
	}
}
