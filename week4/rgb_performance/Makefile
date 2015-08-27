BIN = toGray_v0 toGray_v1 toGray_v2 toGray_v3 toGray_v4

CFLAGS = -Wall -Werror -std=gnu99 -O0 -g
LDFLAGS = `pkg-config --libs --cflags libpng`

all: $(BIN)

toGray_v0: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V0 -DOUTPUT=\"gray_v0.png\"

toGray_v1: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V1 -DOUTPUT=\"gray_v1.png\"

toGray_v2: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V2 -DOUTPUT=\"gray_v2.png\"

toGray_v3: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V3 -DOUTPUT=\"gray_v3.png\"

toGray_v4: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DTOGRAY_V4 -DOUTPUT=\"gray_v4.png\"

clean:
	$(RM) $(BIN) gray_v*.png
