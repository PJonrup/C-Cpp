
#include <stdio.h>


struct person {
    int age;
    char *name;
} flavio, people[20];


typedef struct {    // A name after struct here works but I have not found any use for it.
    int age2;
    char *name2;
} PERSON;


int main(void) {

    struct person steven = {37, "Steven"};

    PERSON jessica = {25, "Jessica"};

    return 0;
}