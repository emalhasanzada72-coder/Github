#include <stdio.h>
int main() {
    int number[5];
    int sum = 0; 
    float average;
    for ( int i = 0; i < 5; i++) {
        printf(" enter number");
        scanf("%d", &number[i]);
        sum += number[i];
        average = sum / 5.0;
     

    }
       printf("my average is %.2f\n", average);
    return 0; 
}