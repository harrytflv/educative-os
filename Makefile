cpu:
	gcc -o cpu cpu.c -Wall

mem:
	gcc -o mem mem.c -Wall

thread:
	gcc -o thread threads.c -Wall -pthread

io:
	gcc -o io io.c -Wall

