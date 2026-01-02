#include <stdio.h>
int main() {
   int number = 1; 
   printf("Enter a number (Enter 0 to stop):\n");
   while (number != 0) {
    scanf("%d", &number );
    printf("You Entered %d\n", number );

   }
   printf(" Program finishide ");
    return 0;

}