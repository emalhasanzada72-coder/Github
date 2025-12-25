#include <stdio.h>
int main() {
    int num1, num2, num3, num4;
    int sum, Multiplication,Division;
printf("Enter 4 number :>\n");
scanf("%d %d %d %d", &num1, &num2, &num3,&num4);
sum = num1 + num2 + num3 + num4;
Multiplication = num1 *  num2 * num3 * num4;
Division = num1 * num2 * num3 / num4;

printf("This is mu sum number %d\n", sum);
printf(" multiplication %d\n",Multiplication );
printf(" Division %d\n", Division);

return 0;


}