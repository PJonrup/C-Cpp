
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main(void) {

    unsigned long time = 0;
    char choice;

    printf("Do you want to start the 'almost' infinite loop? Write Y.\n");
    scanf(" %c", &choice);

    while(choice == 'Y' || choice == 'y') {

        int *i = malloc(sizeof(int));

        if(!i) {
            printf("Could not allocate memory, skipping one iteration!\n");
            Sleep(1000);
            time += 1;
            continue;
        } else {
            printf("M-done, sleeping for 10...\n");
        }

        Sleep(10000);
        time += 10;

        free(i);
        printf("Done freeing...\n");

        Sleep(2000);
        time += 2;

        printf("Slept for %lus\n", time);
    }

    return 0;
}