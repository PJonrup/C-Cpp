#include <stdio.h>


int main(void) {

    /*

    I/O streams:
    stdin   - std input
    stdout  - std output
    stderr  - std error

    - From the C standpoint, there is no difference in reading from a file or the command line.

    */

   int age1 = 37;
   int age2 = 25;
   printf("age1: %d, age2: %d", age1, age2);


   int age3;
   scanf("%d", &age3);

   char name[20];
   scanf("%s", name);

   

}