#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int len = 1;
    int start = 1;
    int count = 9;

    while (k > len * count) {
        k -= len * count;
        len++;
        start *= 10;
        count *= 10;
        if (start > 5000) break;
    }

    int num = start + (k - 1) / len;
    int digit_index = (k - 1) % len;

    char s[10];
    sprintf(s, "%d", num);

    printf("%c", s[digit_index]);

    return 0;
}
