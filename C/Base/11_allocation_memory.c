
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int* ptr_mal;
    int* ptr_cal;
    int n = 5;

    ptr_mal = malloc(n * sizeof(int));    // Allocates (n * int) bytes of memory in the HEAP. Error if trying to access this memory without initialization first.
    ptr_cal = calloc(n, sizeof(int));     // Allocates (n * int) bytes of memory in the HEAP. All allocated blocks initializes to 0.
    // ptr_cal = (int*)calloc(n, sizeof(int));   - Typecasting in C is not needed as malloc and calloc are automatically recasted from void to whatever, This is not the case in C++.

    if (!ptr_mal) {   // check so that the malloc and callod did not fail (split for accuracy).
        printf("Memory not allocated!\n");
        exit(0);
    }

    int n = 10;

    ptr_mal = realloc(ptr_mal, n * sizeof(int));    // re-allocates the previous saved memory within the new allocation size.
    ptr_cal = realloc(ptr_cal, n * sizeof(int));

    if (!ptr_mal) {
        printf("Memory not allocated!\n");
        exit(0);
    }

    /* Do something */

    free(ptr_mal);     // make sure to free allocated memory.
    free(ptr_cal);

    return 0;
}