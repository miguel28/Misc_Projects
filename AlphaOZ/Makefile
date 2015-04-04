all:
	clear
	nasm -f aout -i ./src/boot/ ./src/boot.s -o ./obj/boot.o
	gcc -B ./include/ -c ./src/main.c -o ./obj/main.o -fno-builtin 
	ld -T link.ld -o ./bin/kernel.bin ./obj/boot.o ./obj/main.o