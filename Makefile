
CFLAGS               := -Wall -Wextra -Wpedantic -g -std=gnu++2a
CC                   := g++-10

all:
	$(CC) main.cpp -o main $(CFLAGS)

run: all
	./main < q

