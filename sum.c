#include <stdio.h>
int main() {
    int num1, num2, sum;
    int cuont = 3;
  printf("how mani time do you want to repeat?");
  scanf("%d", &cuont);
    for (int i = 0; i < cuont; i++) {
       
   
    printf("Enter 2 number\n ");
    
    scanf("%d %d", &num1, &num2);
   

    sum = num1 + num2;
    if (sum > 100){
        printf("oh my good this is very big\n");
    }else{
        printf(" this is oky\n");
    }
    printf("His is my sum number %d\n", sum);
    
}
    return 0;

}