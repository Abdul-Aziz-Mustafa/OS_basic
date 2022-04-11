all:B_function.asm A_function.c C_function.c
		nasm -f elf64 -o B_function.o B_function.asm
		gcc -no-pie A_function.c B_function.o C_function.c -o main

run: all	
		./main