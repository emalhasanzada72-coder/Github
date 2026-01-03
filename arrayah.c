#include <stdio.h>
int main() {
    int n[5];
    int sum = 0;
    int max;
    printf("Enter 5 number to sum them up :\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n[i]);
        sum =+ n[i];
    }
    max < sum;
    printf("%d\n", max);
    if (sum > max){
        printf(" max number is %d\n", sum);
    }
    printf("The total sum is: %d\n", sum);
    return 0;
}