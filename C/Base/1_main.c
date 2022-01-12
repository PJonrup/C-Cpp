#include <stdio.h>

/*

Standard:
int main(void) {
    printf("Hello World!");
}

*/


int main(int argc, char *argv[]) {
    // argc - is the number of parameters that were provided in the command line.
    // argv - is an array of strings.

    // For example:
    // gcc hello.c -o hello  -->  argv = {"gcc", "hello.c", "-o", "hello"};

    // for more complex needs of argc and argv you can use packages like getopt.

    return 0;
}