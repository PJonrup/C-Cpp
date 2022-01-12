
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int* ptr_mal;
    int* ptr_cal;
    int n = 5;

    ptr_mal = (int*)malloc(n * sizeof(int));    // Allocates (n * int) bytes of memory. Error if trying to access this memory without initialization first.
    ptr_cal = (int*)calloc(n, sizeof(int));     // Allocates (n * int) bytes of memory. All allocated blocks initializes to 0.

    if (!ptr_mal) {   // check so that the malloc and callod did not fail (split for accuracy).
        printf("Memory not allocated!\n");
        exit(0);
    }

    int n = 10;

    ptr_mal = (int*)realloc(ptr_mal, n * sizeof(int));    // re-allocates the previous saved memory within the new allocation size.
    ptr_cal = (int*)realloc(ptr_cal, n * sizeof(int));

    if (!ptr_mal) {
        printf("Memory not allocated!\n");
        exit(0);
    }

    /* Do something */

    free(ptr_mal);     // make sure to free allocated memory.
    free(ptr_cal);

    return 0;
}