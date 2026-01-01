#include <stdio.h>
#include <string.h>
int main() {
    char s[110];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++){
        int d = s[i] - '0';
        printf("%c", s[i]);
        for (int k = 0; k < d; k++) 
        printf("%c", s[i]);
        printf("\n");

    }
    return 0; 
}