#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "findgcd.h"

#if defined(FINDGCD_V1)
#define FINDGCD(a,b) findGCD_v1(a,b)
#elif defined(FINDGCD_V2)
#define FINDGCD(a,b) findGCD_v2(a,b)
#elif defined(FINDGCD_V3)
#define FINDGCD(a,b) findGCD_v3(a,b)
#else
#error "No such findgcd method"
#endif

#define RANGE_MAX 10000

int main(int argc, char* argv[])
{
        clock_t begin;

        begin = clock();
        for(int i = 2;i < RANGE_MAX; i++){
                for(int j = i + 1 ;j < RANGE_MAX; j++){
                        FINDGCD(i,j);
                }
        }

        printf("%s finished in range 2 ~ %d, time elapsed: %f\n", argv[0] , RANGE_MAX - 1,
               (double) (clock() - begin) / CLOCKS_PER_SEC);

        return 0;
}
