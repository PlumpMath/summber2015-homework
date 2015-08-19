BIN = findLastname

CROSS_COMPILE = arm-linux-gnueabihf-
QEMU_ARM = qemu-arm -L /usr/arm-linux-gnueabihf

CFLAGS = -Wall -Werror -std=gnu99 -O0

all: $(BIN)

findLastname: findgcd.c main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)
