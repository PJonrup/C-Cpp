
#include <stdio.h>

typedef struct {
    char word[20];
    char translation[20];
} dic;

int main(void) {

    int i = 0;
    dic temp[100000];
    char word, translation;
    scanf("%s", &word);
    
    /*

    while (&translation) {
        for (int j = 0; j < i; j++) {
            if (translation == (&temp[i])->translation) {
                printf("%s\n", temp->word);
                break;
            }
            else {
                printf("eh\n");
            }
        }
        if (scanf("%s", word) == 1) {
                continue;
            } else {
                break;
            }
    }*/

    return 0;
}