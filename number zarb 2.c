#include <stdio.h>
int main() {
    int number;
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d:", i + 1);
        scanf("%d", &number);
        printf("result :%d\n", number * 2);
    }
    printf("finished number! \n");
    return 0;
}