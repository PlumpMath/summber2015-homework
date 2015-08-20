#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "phonebook.h"

// find Zywiec

int main(int argc, char *argv[])
{
        clock_t start, end;

        PhoneBook *book = phoneBook_init();

        /* find last name */
        char *to_be_find = "Zywiec";
        printf("Try to find lastName: %s\n", to_be_find);

        start = clock();
        phoneBook_findLastName(to_be_find, book);
        end = clock();

        printf("time use: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);

        phoneBook_free(book);
        return 0;
}
