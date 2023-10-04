package main

import (
"fmt"
"log"
"net/http"
)

func main() {
httpHandleFunc("/", handler)
log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func handler(w http.ResponseWriterm r *http.Request) {
fmt.Fprintf(w, "URL.Path = %q\n", r.URL.Path)
}

