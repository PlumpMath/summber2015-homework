CC = gcc
CFLAGS = -O0 -std=gnu99

all:
	$(CC) $(CFLAGS) findgcd.c bench.c -o bench

clean:
	rm -rf bench
