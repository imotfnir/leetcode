CC = gcc

all: linked_list

test: all
	./linked_list

clean:
	rm -f linked_list

linked_list: linked_list.c
	$(CC) -g -O3 -Wall $< -o $@

.PHONY:
	all clean test