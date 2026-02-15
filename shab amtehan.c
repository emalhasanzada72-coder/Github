#include <stdio.h>

int main(){
int a[5] =  {1, 2, 3, 4, 5};
int *p = a, sum = 0;

for(int i = 0; i < 5; i++){
    sum += *(p + 1);

}
printf("%d\n", sum);
return 0;

}