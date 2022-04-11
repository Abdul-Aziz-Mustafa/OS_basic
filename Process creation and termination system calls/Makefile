all:q1thread.c q1fork.c
	gcc -Wall -save-temps -g -pthread q1fork.c  -o q1fork
	gcc -Wall -save-temps -g -pthread q1thread.c  -o q1thread
run:all
	./q1fork
	./q1thread
	