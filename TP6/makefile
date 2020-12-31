# Makefile TP 6

all: main stack_height

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99

main: main.o
	$(CC) -o main main.o $(CFLAGS)

stack_height: stack_height.o
	$(CC) -o stack_height stack_height.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f main
	rm -f *~
