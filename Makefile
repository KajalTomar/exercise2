main: set.h set.o main.c
	clang -Wall main.c set.o -o main

