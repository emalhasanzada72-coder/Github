#include <stdio.h>

int main() {
    int h, k;
    scanf("%d", &h);
    scanf("%d", &k);

    int total = 2*h + k;

    if (total % 2 == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
