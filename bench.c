#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "findgcd.h"

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

#define RANGE_MIN 2
#define RANGE_MAX 9999

int main(int argc, char *argv[])
{
        struct timespec t_start, t_end;
        clock_t start, stop;
        double elapsed;

        // initial
        for (int i = RANGE_MIN; i < RANGE_MAX; i++) {
                clock_gettime(CLOCK_MONOTONIC, &t_start);
                for (int j = RANGE_MIN; j < RANGE_MAX; j++) {
                        findGCD_v1(i, j);
                }
                clock_gettime(CLOCK_MONOTONIC, &t_end);
                printf("%d %f\n", i,  diff(t_start, t_end).tv_nsec/ 1000.0);
        }

#if 0
        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);
        clock_gettime(CLOCK_MONOTONIC, &t_start);
        for (i = RANGE_MIN; i < RANGE_MAX; i++) {
                for (j = RANGE_MIN; i < RANGE_MAX; i++) {
                        findGCD_v2(i, j);
                }
        }
        clock_gettime(CLOCK_MONOTONIC, &t_end);

        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        for (i = RANGE_MIN; i < RANGE_MAX; i++) {
                for (j = RANGE_MIN; i < RANGE_MAX; i++) {
                        findGCD_v3(i, j);
                }
        }
        clock_gettime(CLOCK_MONOTONIC, &t_end);

        printf("Time elapsed in us: %d\n", (int) diff(t_start, t_end).tv_nsec);
#endif
        return 0;
}
