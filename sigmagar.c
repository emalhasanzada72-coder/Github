#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    long long sum = 0;

    for (int i = -10; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            long long t = i + j;
            sum += (long long)j * j * t * t * t;
        }
    }

    printf("%lld", sum);
    return 0;
}
