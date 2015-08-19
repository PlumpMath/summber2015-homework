#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *db;

// find Zywiec

void database_open()
{
        db = fopen("lastname.txt", "r");
        if (!db) {
                perror("open lastname.txt");
                exit(-1);
        }
}

void database_close()
{
        fclose(db);
}

int main(int argc, char *argv[])
{
//        clock_t start;



        return 0;
}
