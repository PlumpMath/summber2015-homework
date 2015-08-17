#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern uint32_t clz_asm(uint32_t x);

uint32_t clz(uint32_t x) {
        uint32_t n;

        if (x == 0) return 32;
        n = 1;

        if ((x >> 16) == 0) { n += 16; x <<= 16; }
        if ((x >> 24) == 0) { n += 8; x <<= 8; }
        if ((x >> 28) == 0) { n += 4; x <<= 4; }
        if ((x >> 30) == 0) { n += 2; x <<= 2; }

        n = n - (x >> 31);
        return n;
}

int main(int argc, char *argv[])
{

        return 0;
}
