#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int total = 2 * n + 1;
    for (int i = 0; i <= n; i++) {
        int stars = 2 * i + 1;
        int spaces = n - i;
        for (int s = 0; s < spaces; s++)
        printf(" ");
        for  (int s = 0; s < stars; s++)
        printf("*");
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--){
        int stars = 2 * i + 1;
        int spaces = n - 1;
        for (int s = 0; s < spaces; s++)
        printf(" ");
        for (int s = 0; s < stars; s++)
        printf("*");

    }
    return 0; 
}