#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "phonebook.h"

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
        clock_t start, end;
        char buf[MAX_LAST_NAME_SIZE];

        // build phonebook data
        database_open();
        PhoneBook *book, *p;
        book = (PhoneBook *) malloc(sizeof(PhoneBook));
        p = book;
        p->pNext = NULL;

        while(fgets(buf, sizeof(buf), db)) {
                strtok(buf, "\n");
                p = appendName(buf, p);
                // printf("buf is %s\n", buf);
        }
        database_close();

        /* find last name */
        char *to_be_find = "Zywiec";
        printf("Try to find lastName: %s\n", to_be_find);

        p = book;
        start = clock();
        findName(to_be_find, p);
        end = clock();

        printf("time use: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);

        free(book);

        return 0;
}
