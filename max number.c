#include <stdio.h>
int main() {
    int a, b,c;
    int max;
    printf("Enter 2 number :\n");
    scanf("%d %d %d", &a, &b, &c);
    max = a; 
    if (b > max) {
        max = b;

    }
    if (c > max){
        c = max;
    }
    printf("The max number is :%d\n", max);
    
    return 0;
}