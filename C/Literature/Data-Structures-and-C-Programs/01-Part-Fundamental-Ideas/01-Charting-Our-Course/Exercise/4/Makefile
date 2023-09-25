CC = gcc

BASE_C_GLOBS = $(wildcard *.c)
BASE_OBJ_GLOBS = $(BASE_C_GLOBS:.c=.o)

CFLAGS = -Os -Werror
LDFLAGS =

CC_CMD = $(CC) -c -o $@ $< $(CFLAGS)
LD_CMD = $(CC) -o $@ $< $(LDFLAGS)

PROG = 1_1_4 1_1_4_2

all: $(PROG)

1_1_4: 1_1_4.o
1_1_4_2: 1_1_4_2.o
