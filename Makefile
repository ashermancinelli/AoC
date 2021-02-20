
CFLAGS               := -Wall -Wextra -Wpedantic -g -std=gnu++2a
CC                   := g++-10
FC									 := flang

f:
	$(FC) main.f90 -o main $(FCFLAGS)

c:
	$(CC) main.cpp -o main $(CFLAGS)

run: all
	./main < q

