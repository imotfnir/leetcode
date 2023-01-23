# Environment Variable
export MAKE = make
export RM := rm -f
export CP := cp
export MKDIR := mkdir -p
export CC := $(CROSS_COMPILE)gcc
export LD := $(CROSS_COMPILE)ld
export AR := $(CROSS_COMPILE)ar
export SHELL := /bin/sh
export LN := ln -s
export SUDO := sudo

# Vpath
vpath %.c ./src ./library
vpath %.h ./include

# Flags
CFLAGS := -g -O3 -Wall
INCS = ./include
INCFLAG = $(foreach d,$(INCS)/,-I$d)
SRCS = 0021-merge-two-sorted-lists.c 0141-linked-list-cycle.c
RUN = $(SRCS:%.c=%)
LIBS = linked_list.c
OBJS = $(LIBS:%.c=%.o) $(SRCS:%.c=%.o)
DEPS = $(LIBS:%.c=%.d) $(SRCS:%.c=%.d)

all: $(RUN)

rebuild: clean all

test: all
	$(RUN)

clean:
	$(RM) $(RUN) $(OBJS) $(DEPS)

$(RUN): %: %.o $(LIBS:%.c=%.o)
	@echo "Make RUN"
	$(CC) $(CFLAGS) $(INCFLAG) $^ -o $@

$(DEPS): $(LIBS)
	@echo "Make DEPS"
	$(CC) $(INCFLAG) -MM $< -MF $@ -MT '$(patsubst %.d,%.o,$@) $@'

$(OBJS): %.o: %.c
	@echo "Make OBJS"
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

debug:
	@echo "OBJS="$(OBJS)
	@echo "DEPS="$(DEPS)
	@echo "RUN="$(RUN)

.PHONY:
	all rebuild clean test debug

-include $(DEPS)
