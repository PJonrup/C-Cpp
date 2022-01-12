#include <stdio.h>

/*

Only for understandability/readability and only in C (not C++):
If a function SHOULD not have any inparameters, it can sometimes be good
to use the argument void. This tells the compiler that there will not be
any inputs whilst foo() for example tells the compiler that the function
COULD take any number of parameters of unknown types.
This is also a so called *parameter type list* function definition.

Lookup:
Composite type for functions,
Identifier lists

*/

void doSomething(int value, int * var);

int main(void) {

    int a = 6;

    doSomething(5, &a);

    printf("%d", a);

    return 0;
}

void doSomething(int value, int * var) {
    // *var = 2;
    printf("%d and %d\n", value, *var = 2);     // This works too
}