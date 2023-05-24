BIN = main

all: ${BIN}

init: go.mod
	go init ${BIN}

${BIN}: ${BIN}.go
	go build ${BIN}.go

.PHONY: init ${BIN}
