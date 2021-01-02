all: compile run

compile:
	gcc -Wall -ansi final.c -o test

run:
	valgrind --leak-check=full ./test

remove:
	rm test
