#include <stdio.h>
int main() {
    int a[2][2];
    int b[2][2];
    int sum[2][2];// ابتدا تمام اعداد ماتریکس اول را میگیرمیم 
   printf("Enter 4 number for matrix A:\n");
   for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++) {
        scanf("%d", &a[i][j]);
    }
   }//سپس تمام اعداد ماتریکس دوم را می گیریم 
   printf("Enter 4 numbers for matrix B:\n");
   for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++) {
        scanf("%d", &b[i][j]);
    }
   }// و در اخیر هردو ماتریکس را باهم جمع می کنیم 
   printf("\n The sum of matrix is :\n");
   for (int i = 0; i < 2; i++){
    for (int j = 0; j< 2; j++){
        sum[i][j] = a[i][j] + b[i][j];
        printf("%d\n", sum[i][j]);
    }
    printf("\n");
   }

    return 0;
}