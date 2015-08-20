#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook.h"

static FILE *database_open(const char *datafile)
{
        FILE *db = fopen(datafile, "r");
        if (NULL == db) {
                perror("open database file");
                exit(-1);
        }

        return db;
}

static void database_close(FILE *db)
{
        if (NULL != db)
                fclose(db);
}

PhoneBook *phoneBook_init()
{
        FILE *db = database_open("lastname.txt");

        char buf[MAX_LAST_NAME_SIZE];

        PhoneBook *phoneBook = (PhoneBook *) malloc(sizeof(PhoneBook));
        phoneBook->pNext = NULL;

        while(fgets(buf, sizeof(buf), db)) {
                strtok(buf, "\n");
                phoneBook = phoneBook_appendLastName(buf, phoneBook);
                // printf("buf is %s\n", buf);
        }

        database_close(db);
        return phoneBook;
}

void phoneBook_free(PhoneBook *phoneBook)
{
        if (NULL != phoneBook)
                free(phoneBook);
}

PhoneBook *phoneBook_findLastName(char lastName[], PhoneBook *pHead)
{
        while (pHead != NULL) {
                // case insensitive
                if (0 == strcasecmp(lastName, pHead->lastName)) {
                        printf("Find lastName!!\n");
                        return pHead;
                }
                pHead = pHead->pNext;
        }

        return NULL;
}

PhoneBook *phoneBook_appendLastName(char lastName[], PhoneBook *pHead)
{
        pHead->pNext = (PhoneBook *) malloc(sizeof(PhoneBook));
        pHead = pHead->pNext;
        strcpy(pHead->lastName, lastName);
        pHead->pNext = NULL;

        return pHead;
}