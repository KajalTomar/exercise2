main: set.h set1.o main.c
	clang -Wall main.c set1.o -o main

clear:
	main.o set1.o main
