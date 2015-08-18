#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* original version */
typedef struct __PHONE_BOOK_ENTRY {
        char LastName[MAX_LAST_NAME_SIZE];
        char FirstName[16];
        char email[16];
        char phone[10];
        char cell[10];
        char addr1[16];
        char addr2[16];
        char city[16];
        char state[2];
        char zip[5];
        __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;

PhoneBook *findName(char lastName[], PhoneBook *pHead);
PhoneBook *appendName(char lastName[], PhoneBook *pHead);


#endif /* PHONEBOOK_H */