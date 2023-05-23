BIN: main

all: init main

init: go.mod
	go init ${BIN}

main: main.go
	go build main.go

.PHONY: init main
