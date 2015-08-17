BIN = clz

CFLAGS = -Wall -Werror -std=gnu99 -O0

all: $(BIN)

clz: main.c clz.s
	$(CC) $(CFLAGS) -o $@ $^ -DFINDGCD_V1

clean:
	$(RM) $(BIN)
