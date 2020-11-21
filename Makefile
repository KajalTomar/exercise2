main: set.h set.c main.c
	clang -Wall main.c set.o -o main

set.o: set.h set.c
	clang -Wall -c set.c -o set.o

clean:
	rm set.o main.o main
