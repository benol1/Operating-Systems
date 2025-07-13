all: task1 task2a task2b task2c task3

task1: task1.asm asm_io.inc
	nasm -f elf32 task1.asm
	gcc -m32 -o task1 task1.o asm_io.o

task2a: task2a.asm asm_io.inc
	nasm -f elf32 task2a.asm
	gcc -m32 -o task2a task2a.o asm_io.o

task2b: task2b.asm asm_io.inc
	nasm -f elf32 task2b.asm
	gcc -m32 -o task2b task2b.o asm_io.o

task2c: task2c.asm asm_io.inc
	nasm -f elf32 task2c.asm
	gcc -m32 -o task2c task2c.o asm_io.o

task3: task3.c
	gcc -m32 -o task3 task3.c

clean:
	rm -f *.o task1 task2a task2b task2c task3
