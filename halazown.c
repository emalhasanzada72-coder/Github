#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 1) {
        printf("0 0");
        return 0;
    }

    long long k = ceil((sqrt(n) - 1) / 2);
    long long maxVal = (2 * k + 1) * (2 * k + 1);
    long long d = maxVal - n;

    long long x, y;

    if (d < 2 * k) {
        x = k - d;
        y = -k;
    }
    else if (d < 4 * k) {
        x = -k;
        y = -k + (d - 2 * k);
    }
    else if (d < 6 * k) {
        x = -k + (d - 4 * k);
        y = k;
    }
    else {
        x = k;
        y = k - (d - 6 * k);
    }

    printf("%lld %lld", x, y);
    return 0;
}
