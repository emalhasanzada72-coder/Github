#include <stdio.h>
 
int addNumbers(int a, int b) {
    int result;
    result = a + b;
    return result;
    
}
int main() {
    int num1, num2, sum;
    printf("Enter tow number >:)<\n");
    scanf("%d %d", &num1, &num2);
    sum = addNumbers(num1, num2);
    printf("This is my sum number >:)< %d\n", sum);
    return 0;
}