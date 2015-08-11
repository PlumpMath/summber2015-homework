#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int findGCD_v1(int a, int b) {
        while (1) {
                if (a > b) a -= b;
                else if (a < b) b -= a;
                else return a;
        }
}

int findGCD_v2(int a, int b) {
        while (1) {
                a %= b;
                if (a == 0) return b;
                if (a == 1) return 1;
                b %= a;
                if (b == 0) return a;
                if (b == 1) return 1;
        }
}

int findGCD_v3(int a, int b) {
        while (1) {
                if (a > (b * 4)) {
                        a %= b;
                        if (a == 0) return b;
                        if (a == 1) return 1;
                } else if (a >= b) {
                        a -= b;
                        if (a == 0) return b;
                        if (a == 1) return 1;
                }
                if (b > (a * 4)) {
                        b %= a;
                        if (b == 0) return a;
                        if (b == 1) return 1;
                } else if (b >= a) {
                        b -= a;
                        if (b == 0) return a;
                        if (b == 1) return 1;
                }
        }
}

struct timespec diff(struct timespec start, struct timespec end)
{
        struct timespec temp;
        if ((end.tv_nsec-start.tv_nsec)<0) {
                temp.tv_sec = end.tv_sec-start.tv_sec-1;
                temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
        } else {
                temp.tv_sec = end.tv_sec-start.tv_sec;
                temp.tv_nsec = end.tv_nsec-start.tv_nsec;
        }
        return temp;
}

int main(int argc, char *argv[])
{
        int a = 5000;
        int b = 2323;

        struct timespec t_start, t_end;
        clock_t start, stop;
        double elapsed;


        int i, j;
#define MAX 9999
#define MIN 2

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        for (i = MIN; i < MAX; i++) {
                for (j = MIN; i < MAX; i++) {
                        findGCD_v1(i, j);
                }
        }
        clock_gettime(CLOCK_MONOTONIC, &t_end);

        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        for (i = MIN; i < MAX; i++) {
                for (j = MIN; i < MAX; i++) {
                        findGCD_v2(i, j);
                }
        }
        clock_gettime(CLOCK_MONOTONIC, &t_end);

        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        for (i = MIN; i < MAX; i++) {
                for (j = MIN; i < MAX; i++) {
                        findGCD_v3(i, j);
                }
        }
        clock_gettime(CLOCK_MONOTONIC, &t_end);

        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);

        return 0;
}
