#include <stdio.h>
#include <stdlib.h>

#include "rgb.h"

/* original version */
void rgba_to_bw(uint32_t *bitmap, int width, int height, long stride) {
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = 0; row < height; row++) {
                for (col = 0; col < width; col++) {
                        pixel = bitmap[col + row + stride / 4];
                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
                        bitmap[col + row * stride / 4] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

/* optimize version */
void rgba_to_bw_v1(uint32_t *bitmap, int width, int height, long stride) {
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = height; row != 0; row--) {
                for (col = width; col != 0; col--) {
                        pixel = bitmap[col + row + stride / 4];
                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
                        bitmap[col + row * stride / 4] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

int main(int argc, char *argv[])
{

        return 0;
}
