#include <stdio.h>
int main() {
    float num1, num2, num3;
    float average;
    printf("Enter three float number :)\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    average = (num1 + num2 + num3) /3.0;
    printf("this is my float number %f\n", num1, num2, num3);
    return 0;

}
