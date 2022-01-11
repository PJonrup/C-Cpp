

// "#" can be thought of as things that the preprocessor handels for us before compile time.
#include <stdio.h>

// Macros (limited to one line definitions)
#define POWER(x) ((x) * (x))

// If defined
#define VALUE 1
#define DEBUG 0

/* 
Predefined symbolic constants:
__LINE__: translates to the current line in the source code file.
__FILE__: translates to the anme fo the file.
__DATE__: translates to the compulation data, in the MM DD YYYY format.
__TIME__: translates to the compulation time, in the hh:mm:ss format

*/

int main(void) {

    printf("%u\n", POWER(4));


#ifdef VALUE    // or #if defined to checke if VALUE has been defined, there is also, #if defined, #if !defined 
    printf("Value is defined\n");
#else
    printf("Value is not defined\n");
#endif


#if DEBUG == 0
    printf("I am NOT debugging\n");
#else
    printf("I am debugging\n");
#endif

}

// DEBUG can also be used as follows:

#if DEBUG
    /* code only sent to compiler if DEBUG is not 0 */
#endif