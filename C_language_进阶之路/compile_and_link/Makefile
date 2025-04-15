GCC = gcc

#-g debug message
#-O optimization code make it exec faster
#CFLAGS = -g -Wall -Wshadow
CFLAGS = -O -Wall -Wshadow

prog: areDistinct.o main.o
	$(GCC) $(CFLAGS) areDistinct.o main.o -o prog

areDistinct.o: areDistinct.c
	$(GCC) $(CFLAGS) -c areDistinct.c

main.o: main.c
	$(GCC) $(CFLAGS) -c main.c


clean:
	rm -rf *.o prog outputs/*

    