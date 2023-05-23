package main

import (
	"fmt"
	"github.com/fatih/color"
	"net/http"
)

func handler(writer http.ResponseWriter, request *http.Request) {
	red := color.New(color.FgRed)
	fmt.Fprintf(writer, "Hello World, %s:%s!", request.URL.Path[1:], red.SprintFunc()("Test"))
}

func main() {
	http.HandleFunc("/", handler)
	http.ListenAndServe(":8080", nil)
}
