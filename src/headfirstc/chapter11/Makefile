error.o: error.o
	gcc -c error.c

main.o: main.c error.c
	gcc -c main.c

launch: error.c main.c
	gcc main.c error.c -o launch
