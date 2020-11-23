main: set.h set3.o main.c
	clang -Wall main.c set3.o -o main

clear:
	main.o set3.o main
