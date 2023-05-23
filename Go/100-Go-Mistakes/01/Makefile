BIN = 01
GO = go

build:
	GOARCH=amd64 GOOS=linux ${GO} build -o ${BIN} main.go

run: build
	./${BIN}

clean:
	go clean
	rm -f ${BIN}

.PHONY: build clean run


all: update

update:
	sudo pacman -Syu --noconfirm
