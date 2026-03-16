CC = gcc
CFLAGS = -Wall -std=gnu99 -g -fPIC
LD = gcc
LDFLAGS = -L.
AR = ar

all: greet.dynamic greet.static

greet.dynamic: libgreet.so main.o # Linking stage
	$(LD) $(LDFLAGS) -o $@ main.o -lgreet

greet.static: libgreet.a main.o # Linking stage
	$(LD) $(LDFLAGS) -static -o $@ main.o -lgreet

libgreet.so: greet.o
	$(LD) $(LDFLAGS) -shared -o $@ $<

libgreet.a: greet.o
	$(AR) rcs $@ $<

greet.o: greet.c # Compiling stage
	$(CC) $(CFLAGS)	-c -o greet.o greet.c

main.o: main.c # Compiling stage, $< means only _first_ prerequisite
	$(CC) $(CFLAGS)	-c -o $@ $< 

clean: 
	rm -f program greet.o main.o

