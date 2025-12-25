#include <stdio.h>
int main() {
    int number;
    for (int i = 0; i < 3; i++){
    printf("Enter one number:><\n");
    scanf("%d", &number);
    if (number == 0)
    printf("The number is zero:>< %d\n", number);
    else if (number % 2 == 0)
    printf("The number id even:>< %d\n", number);
    else 
    printf("the number is odd:>< %d\n", number);
    }
    return 0;
}