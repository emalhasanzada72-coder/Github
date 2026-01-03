
#include <stdio.h>
int main() {
   int password;
   int correctpassword = 1234;
   for (int i = 0; i < 3; i++){
    printf("Enter your password number %d\n", i + 1);
    scanf("%d", &password);
    if (password == correctpassword) {
        printf("welcome your coffee \n");
        break;
    }else{
        printf("your passworde is not qabowl enter to rownd %d\n", 2-i);
    }
   }
    return 0;
}