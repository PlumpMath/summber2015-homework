#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* original version */
#if defined(PHONEBOOK_ORIGIN)
typedef struct __PHONE_BOOK_ENTRY {
        char lastName[MAX_LAST_NAME_SIZE];
        char firstName[16];
        char email[16];
        char phone[10];
        char cell[10];
        char addr1[16];
        char addr2[16];
        char city[16];
        char state[2];
        char zip[5];
        struct __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;
#else
#error "You must specify one implement of PhoneBook structure."
#endif


PhoneBook *phoneBook_init();
void phoneBook_free(PhoneBook *phoneBook);
PhoneBook *phoneBook_findLastName(char lastName[], PhoneBook *pHead);
PhoneBook *phoneBook_appendLastName(char lastName[], PhoneBook *pHead);

#endif /* PHONEBOOK_H */