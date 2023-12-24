srcdir = .

SRC_DIRS = 05/*
BASE_GLOBS = $(addsuffix /*.c,$(SRC_DIRS))
BASE_SRCS = $(sort $(wildcard $(BASE_GLOBS)))
BASE_OBJS = $(addsuffix .o,$(basename $(BASE_SRCS)))
ALL_OBJS = $(addprefix obj/, $(notdir $(sort $(BASE_OBJS))))

OBJ_DIRS = $(dir $(ALL_OBJS))

CFLAGS_C99FSE = -std=c99 -ffreestanding -Wpedantic
CFLAGS_ALL = $(CFLAGS_C99FSE)
CFLAGS_ALL += -D_XOPEN_SOURCE=700 -I$(srcdir)/lib

CC_CMD = $(CC) $(CFLAGS_ALL) -c -o $@ $<

LIB_DIR = lib
LIB_GLOBS = $(addsuffix /*.c,$(LIB_DIR))
LIB_SRCS = $(sort $(wildcard $(LIB_GLOBS)))
LIB_OBJS = $(addsuffix .o,$(basename $(LIB_SRCS)))
ALL_LIB_OBJS = $(addprefix obj/, $(notdir $(sort $(LIB_OBJS))))

all: $(ALL_LIB_OBJS) $(ALL_OBJS)

$(ALL_OBJS): | $(OBJ_DIRS)

$(OBJ_DIRS):
	mkdir -p $@

$(ALL_LIB_OBJS): $(LIB_SRCS)
	$(CC_CMD)

$(ALL_OBJS): $(BASE_SRCS) $(ALL_LIB_OBJS)
	$(CC_CMD)


.PHONY: all




