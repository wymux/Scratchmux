CC = gcc

BASE_C_GLOBS = $(wildcard *.c)
BASE_OBJ_GLOBS = $(BASE_C_GLOBS:.c=.o)

CFLAGS = -Os -Werror
LDFLAGS =

CC_CMD = $(CC) -c -o $@ $< $(CFLAGS)
LD_CMD = $(CC) -o $@ $< $(LDFLAGS)

PROG = 1_1_3

all: $(PROG)

$(PROG): $(BASE_OBJ_GLOBS)
	$(LD_CMD)
