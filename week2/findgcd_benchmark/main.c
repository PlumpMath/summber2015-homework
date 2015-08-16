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

int main(int argc, char* argv[])
{
        if (argc != 2 ) {
                printf("Usage: %s <range>\n", argv[0]);
                return 0;
        }

        unsigned int range_max = atoi(argv[1]);

        clock_t begin = clock();
        for(int i = 2;i < range_max + 1; i++){
                for(int j = i + 1 ;j < range_max + 1; j++){
                        FINDGCD(i,j);
                }
        }

        printf("%s finished in range 2 ~ %d and time elapsed: %f\n", argv[0] , range_max,
               (double) (clock() - begin) / CLOCKS_PER_SEC);

        return 0;
}
