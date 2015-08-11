CC = gcc
CFLAGS = -O0

all:
	$(CC) $(CFLAGS) bench.c -o bench

clean:
	rm -rf bench
