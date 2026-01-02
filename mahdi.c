#include <stdio.h>

int between(int x, int l, int r) {
    if (l < r) return x > l && x < r;
    return x > l || x < r;
}

int main() {
    int n, a, b, c, d;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    int cut = (between(c, a, b) ^ between(d, a, b));

    if (cut)
        printf("4");
    else
        printf("3");

    return 0;
}
