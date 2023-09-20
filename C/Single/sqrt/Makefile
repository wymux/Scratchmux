CC_CMD = $(CC) $(CFLAGS) -c $<
LD_CMD = $(CC) $(CFLAGS) -o $@ $<

BASE_C_GLOBS = $(wildcard *.c)
BASE_OBJ_GLOBS = $(BASE_C_GLOBS:.c = .o)

PROG = sqrt

all: $(PROG)

$(PROG).o: $(PROG).c
	$(CC_CMD)

$(PROG): $(BASE_OBJ_GLOBS)
	$(LD_CMD)

