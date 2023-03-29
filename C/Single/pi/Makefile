CC = gcc

BASE_C_GLOBS = $(wildcard *.c)
BASE_OBJ_GLOBS = $(BASE_C_GLOBS:.c=.o)

CFLAGS = -Os -g -Werror
LDFLAGS =

CC_CMD = $(CC) -c -o $@ $< $(CFLAGS)
LD_CMD = $(CC) -o $@ $< $(LDFLAGS)

PROG = pi

all: $(PROG)

$(PROG): $(BASE_OBJ_GLOBS)
	$(LD_CMD)
