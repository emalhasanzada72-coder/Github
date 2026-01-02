#include <stdio.h>
int main() {
   int num1, num2, num3, num4, num5;

   for (int i = 0; i < 5; i++){
   printf("Enter 5 number :)\n");
   scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
   if(i = 5){
    printf("finishd!");
   }
    printf("%d\n= %d\n = %d\n= %d\n = %d\n", num1 *2 , num2 *2, num3 *2, num4 *2, num5 *2);

   }
    return 0;

}