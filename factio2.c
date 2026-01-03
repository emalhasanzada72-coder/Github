#include <stdio.h>
void printstars() {
    printf("*****************************");
}
int main() {
    int  a, b, sum;
    printstars();
    printf("Enter tow number:");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printstars();
    printf("the result is %d\n", sum);
    printstars();
    return 0;
}