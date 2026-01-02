#include <stdio.h>
int main( ){
   char answer;
   printf("Do you want to continue? (y/n):");
   scanf("%c", &answer);
   if (answer == 'y'){
    printf("lets go😜 \n");
   } else if (answer == 'n'){
    printf("Stopping the program ......\n🙃");
   }else {
    printf("I dont understand that character 😜\n");

   }
   return 0;
}