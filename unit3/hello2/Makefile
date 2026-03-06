# TARGET:    SOURCES
#       COMMAND

CC=gcc

all: hello.dynamic hello.static

hello.dynamic: hello.o
	$(CC) hello.o -o hello.dynamic

hello.static: hello.o
	$(CC) -static hello.o -o hello.static

hello.o: hello.c
	$(CC) -c hello.c -o hello.o
