GCC = gcc
CFLAGS = -g -Wall -Wshadow
VALGRIND = valgrind --tool=memcheck --leak-check=full
VALGRIND += --verbose --log-file=
OBJS = mysort.o main.o
HDRS = mysort.h 

mysort: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

test: mysort
	$(VALGRIND) log6 ./mysort 6 < input6 > output6
	diff output6  expected6
	$(VALGRIND) log20 ./mysort 20 < input20 > output20
	diff output20 expected20
	$(VALGRIND) log50 ./mysort 50 < input50 > output50
	diff output50  expected50
	$(VALGRIND) log100 ./mysort 100 < input100 > output100
	diff output100 expected100
testgen: testgen.c
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