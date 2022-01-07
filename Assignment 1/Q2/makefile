all: 
	gcc -c c.c;
	nasm -f elf64 -o b1.o b1.asm;

	gcc -c a.c;
	gcc -c wrapperfun.c;
	gcc -c main.c;
	
	gcc -o main main.o a.o b1.o c.o wrapperfun.o;
	./main

clean:
	rm *.o;
	rm main;