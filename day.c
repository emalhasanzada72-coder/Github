#include <stdio.h>
int main(){
 int Board[4][4];
 Board[4][4] = {
  {1,3,4,5},
  {1,3,2,4},
  {9,9,8,7},
  {4,5,6,7}
 };
 int sum = 1;
 for(int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){
    printf("mac number is ", i + 1);
  }
 }
 sum +=Board[i][j];
 for (int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){
    printf("%d\n", Board[i][j]);
  }
  printf("%d\n", sum);
 }

  return 0;
}