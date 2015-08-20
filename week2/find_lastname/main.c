#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "phonebook.h"

int toValue(char ch){
        int val;
        switch(ch){
        case 'a': val =  0;break; case 'b': val =  1;break;
        case 'c': val =  2;break; case 'd': val =  3;break;
        case 'e': val =  4;break; case 'f': val =  5;break;
        case 'g': val =  6;break; case 'h': val =  7;break;
        case 'i': val =  8;break; case 'j': val =  9;break;
        case 'k': val = 10;break; case 'l': val = 11;break;
        case 'm': val = 12;break; case 'n': val = 13;break;
        case 'o': val = 14;break; case 'p': val = 15;break;
        case 'q': val = 16;break; case 'r': val = 17;break;
        case 's': val = 18;break; case 't': val = 19;break;
        case 'u': val = 20;break; case 'v': val = 21;break;
        case 'w': val = 22;break; case 'x': val = 23;break;
        case 'y': val = 24;break; case 'z': val = 25;break;
        case 'A': val = 26;break; case 'B': val = 27;break;
        case 'C': val = 28;break; case 'D': val = 29;break;
        case 'E': val = 30;break; case 'F': val = 31;break;
        case 'G': val = 32;break; case 'H': val = 33;break;
        case 'I': val = 34;break; case 'J': val = 35;break;
        case 'K': val = 36;break; case 'L': val = 37;break;
        case 'M': val = 38;break; case 'N': val = 39;break;
        case 'O': val = 40;break; case 'P': val = 41;break;
        case 'Q': val = 42;break; case 'R': val = 43;break;
        case 'S': val = 44;break; case 'T': val = 45;break;
        case 'U': val = 46;break; case 'V': val = 47;break;
        case 'W': val = 48;break; case 'X': val = 49;break;
        case 'Y': val = 50;break; case 'Z': val = 51;break;
        default:
                printf("ERROR: not support\n");
                exit(-1);
        }
        return val;
}

char toChar(int val){
        char ch;
        switch(val){
        case  0: ch = 'a';break; case  1: ch = 'b';break;
        case  2: ch = 'c';break; case  3: ch = 'd';break;
        case  4: ch = 'e';break; case  5: ch = 'f';break;
        case  6: ch = 'g';break; case  7: ch = 'h';break;
        case  8: ch = 'i';break; case  9: ch = 'j';break;
        case 10: ch = 'k';break; case 11: ch = 'l';break;
        case 12: ch = 'm';break; case 13: ch = 'n';break;
        case 14: ch = 'o';break; case 15: ch = 'p';break;
        case 16: ch = 'q';break; case 17: ch = 'r';break;
        case 18: ch = 's';break; case 19: ch = 't';break;
        case 20: ch = 'u';break; case 21: ch = 'v';break;
        case 22: ch = 'w';break; case 23: ch = 'x';break;
        case 24: ch = 'y';break; case 25: ch = 'z';break;
        case 26: ch = 'A';break; case 27: ch = 'B';break;
        case 28: ch = 'C';break; case 29: ch = 'D';break;
        case 30: ch = 'E';break; case 31: ch = 'F';break;
        case 32: ch = 'G';break; case 33: ch = 'H';break;
        case 34: ch = 'I';break; case 35: ch = 'J';break;
        case 36: ch = 'K';break; case 37: ch = 'L';break;
        case 38: ch = 'M';break; case 39: ch = 'N';break;
        case 40: ch = 'O';break; case 41: ch = 'P';break;
        case 42: ch = 'Q';break; case 43: ch = 'R';break;
        case 44: ch = 'S';break; case 45: ch = 'T';break;
        case 46: ch = 'U';break; case 47: ch = 'V';break;
        case 48: ch = 'W';break; case 49: ch = 'X';break;
        case 50: ch = 'Y';break; case 51: ch = 'Z';break;
        default:
                printf("ERROR: not support\n");
                exit(-1);
        }
        return ch;
}


char *encode(char *str)
{

}

void decode(char *str)
{

}


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
