
// Run files with: 
// cpp file.c -o file

// "#" can be thought of as things that the preprocessor handels for us.
#include <stdio.h>

// This is called a "symbolic constant" and is done by the preprocessor and not during compilation.
#define VALUE 1
#define PI 3.14
#define NAME "Steven"


const int DEBUG = 0;


int main(void) {

    return 0;
}

/*
    ----------- Format Specifiers -----------

    %c                  - char
    %d                  - signed int
    %e or %E            - scientific notation of float
    %f                  - float
    %g or %G            - 
    %hi                 - signed short integer
    %hu                 - unsigned short int
    %i                  - unsigned int
    %l or %ld or %li    - long
    %lf                 - double
    %Lf                 - long double
    %lu                 - unsigned int or unsigned long
    %lli or %lld        - long long
    %llu                - unsigned long long
    %o                  - octal representation
    %p                  - pointer
    %s                  - string
    %u                  - unsigned int
    %x or %X            - hexadecimal representation
    %n                  - prints nothing
    %%                  - prints % character

    %126s               - prevent buffer overflow and allows for the nul terminator.

    - minus symbol tells left alignment
    - number after % specifies minimum field width
    - period (.) is used to separate field width and precision

*/