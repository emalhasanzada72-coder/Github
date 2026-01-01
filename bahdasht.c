#include <stdio.h>
int main() {
    int x, y;
    for (int i = 0; i < 3; i++) {
    if (scanf("%d %d", &x, &y) != 2) return 0;
    int final_grade;
    if(y == 0) {
        final_grade = 20;

    }else if (y == 7) {
        final_grade = x;
    } else {

    
        final_grade = x - y;
        if (final_grade < 0) {
            final_grade = 0;
        }
    } 
    printf(" togedar number %d\n", final_grade);
}
    return 0;
}