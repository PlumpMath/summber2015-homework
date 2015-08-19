
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook.h"

PhoneBook *findName(char lastName[], PhoneBook *pHead)
{
        while (pHead != NULL) {
                // case insensitive
                if (0 == strcasecmp(lastName, pHead->lastName))
                        return pHead;
                pHead = pHead->pNext;
        }

        return NULL;
}

PhoneBook *appendName(char lastName[], PhoneBook *pHead)
{
        return NULL;
}