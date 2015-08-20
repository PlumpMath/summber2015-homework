#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_BUFFER_SIZE 16

/* original version */
#if defined(PHONEBOOK_ORIGIN)

#define MAX_LAST_NAME_SIZE 16
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
#define phonebook_optimize(x) phonebook_optimize_v0(x)

/* Optimize version v1 */
#elif defined(PHONEBOOK_V1)

#define MAX_LAST_NAME_SIZE 4
typedef struct __PHONE_BOOK_ENTRY {
        char lastName[MAX_LAST_NAME_SIZE];
        char firstName[4];
        char email[4];
        char phone[1];
        char cell[3];
        char addr1[4];
        char addr2[4];
        char city[4];
        char state[1];
        char zip[2];
        struct __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;
#define phonebook_optimize(x) phonebook_optimize_v1(x)

/* Error */
#else
#error "You must specify one implement of PhoneBook structure."
#endif

PhoneBook *phoneBook_init();
void phoneBook_free(PhoneBook *phoneBook);
PhoneBook *phoneBook_findLastName(char lastName[], PhoneBook *pHead);
PhoneBook *phoneBook_appendLastName(char lastName[], PhoneBook *pHead);

void phonebook_optimize_v0(char *buf);
void phonebook_optimize_v1(char *buf);
void phonebook_optimize_v2(char *buf);

#endif /* PHONEBOOK_H */