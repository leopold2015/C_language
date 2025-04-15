GCC = gcc
CFLAGS = -g -Wall -Wshadow

testgen : testgen.c
	$(GCC) testgen.c -o testgen

inputgen: testgen
	./testgen 6  > input6
	./testgen 20  > input20
	./testgen 50  > input50
	./testgen 100  > input100
	sort -n input6  > expected6
	sort -n input20  > expected20
	sort -n input50  > expected50
	sort -n input100  > expected100

clean:
	rm testgen input* expected*
