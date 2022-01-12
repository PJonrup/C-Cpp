
// This is called a "symbolic constant" and is done by the preprocessor and not during compilation.
#define YEAR 1998

#include <stdio.h>
#include <string.h>

/*

Global variables are static by default.

Local variables are declared on the stack, by default, unless you explicitly
allocate them on the Heap using pointers. (OBS: Memory management is needed).

Static variables (ex. inside of functions) only initiates the first time the function is called.

*/

typedef int NUMBER;
NUMBER one = 1;

typedef enum {
    MONDAY,         // 0
    TUESDAY,        // 1
    WEDNESDAY = 5,  // 5
    THURSDAY,       // 6
    FRIDAY,         // etc.
    SATURDAY,
    SUNDAY
} weekday;

int incrementAge(void);

int main(void) {

    char c = 50;    // ASCII: -128->127
    int i = 24;
    short is = 50;
    long il = 123;

    printf("%u\n", TUESDAY);

    printf("%u\n", i);

    unsigned char uc = 0;   // 0-255
    unsigned int ui = 0;    // 0-65,535
    unsigned short us = 0;  // 0-65,535
    unsigned long ul = 0;   // 0-4,294,967,295

    // No protection when exceeding limits.
    // Limits are also different from system to system, although these should be minimum.

    float f = 5.5e-3;           // usually 32bit (24) with values 10^+37-10^37
    double d = 4253.647;        // usually 64bits (53)
    long double type = -2.3e+12;  // usually 80bit (64)

    /* checking sizes on a system can be done with the */ sizeof(type); //function.

    int const BIRTH = 1998;     // can also be done as on line2.

    
    // -------------------- Arrays --------------------

    int prices[5];  // 5 integers at position index [0,1,2,3,4]
    int priceinit[5] = {5,3,2,5,1};


    // -------------------- "Strings" --------------------

    char name[7];
    char name_sol_init[5] = {'W', 'r', 'o', 'o', 'm'};      // this works.
    char name_mul_init[6] = "Wroom";    // length is 6 because init with double quotes does not include '\0' as a final character.
    char temp10[] = "Hello there";

    printf("%s\n", temp10);

    // -------------------- Strings --------------------

    /* #include <string.h> gives access too:
    strcpy()    - copy string
    strcat()    - append string
    strcmp()    - compare string
    strncmp()   - compare first n characters of string
    strlen()    - calculates length of string
    ... and more.

    */


    // -------------------- Pointers --------------------

    int age = 24;
    printf("%p\n", &age);     // will print address in memory.

    int * address = &age;
    printf("%u\n", *address);

    int prices2[3] = {5, 4, 3};
    printf("%u\n", *prices2);      // 5
    printf("%u\n", *(prices2 + 1));  // 4


    // -------------------- Static Variables --------------------

    static int temp5;

    printf("%d\n", incrementAge());
    printf("%d\n", incrementAge());
    printf("%d\n", incrementAge());

    return 0;

}

int incrementAge(void) {
    static int age5;    // = 0 is not needed for static variables.
    static int ages[3]; // = {0, 0, 0}
    age5++;
    return age5;
}