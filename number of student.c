#include <stdio.h>
int main( ) {
    int grades[5];
    int max = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter of your number dars%d\n", i + 1);
        scanf("%d", &grades[i]);
        max = 
    }
    printf("\n--- list of your number---\n");
    for (int i = 0; i < 5; i++) {
        printf("number of your dars is %d: %d\n", i + 1, grades[i]);

    }
    return 0; 
}