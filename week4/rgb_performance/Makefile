BIN = toGray_v0 toGray_v1 toGray_v2 toGray_v3

CFLAGS = -Wall -Werror -std=gnu99 -O0
LDFLAGS = `pkg-config --libs --cflags libpng`

all: $(BIN)

toGray_v0: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V0

toGray_v1: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V1

toGray_v2: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V2

toGray_v3: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V3

clean:
	$(RM) $(BIN) gray_v*.png
