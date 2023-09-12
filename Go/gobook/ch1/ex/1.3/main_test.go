package main

import (
	"testing"
)

func main_test(b *testing.B) {
	for i := 0; i < b.N; i++ {
		echo1()
		echo2()
		echo3()
	}
}
