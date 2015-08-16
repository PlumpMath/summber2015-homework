BIN = findGCD_v1 findGCD_v2 findGCD_v3

CROSS_COMPILE = arm-linux-gnueabihf-
QEMU_ARM = qemu-arm -L /usr/arm-linux-gnueabihf

CFLAGS = -Wall -Werror -std=gnu99 -O0

all: $(BIN)

findGCD_v1: findgcd.c main.c
	$(CC) $(CFLAGS) -o $@ $^ -DFINDGCD_V1

findGCD_v2: findgcd.c main.c
	$(CC) $(CFLAGS) -o $@ $^ -DFINDGCD_V2

findGCD_v3: findgcd.c main.c
	$(CC) $(CFLAGS) -o $@ $^ -DFINDGCD_V3

clean:
	$(RM) $(BIN)
