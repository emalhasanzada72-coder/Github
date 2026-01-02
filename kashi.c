#include <stdio.h>

long long ans[70];

void solve(long long m, long long n) {
    if (m == 0 || n == 0) return;

    long long k = 1;
    while ((k << 1) <= m && (k << 1) <= n) k <<= 1;

    long long cnt = (m / k) * (n / k);
    ans[0] += cnt;

    solve(m % k, n);
    solve(m - m % k, n % k);
}

int main() {
    long long m, n;
    scanf("%lld %lld", &m, &n);

    for (int i = 0; i < 70; i++) ans[i] = 0;

    long long mm = m, nn = n;
    while (mm > 0 && nn > 0) {
        long long k = 1, p = 0;
        while ((k << 1) <= mm && (k << 1) <= nn) {
            k <<= 1;
            p++;
        }

        long long cnt = (mm / k) * (nn / k);
        ans[p] += cnt;

        long long rm = mm % k;
        long long rn = nn % k;

        solve(rm, nn);
        solve(mm - rm, rn);

        break;
    }

    for (int i = 60; i >= 0; i--) {
        if (ans[i] > 0)
            printf("%lld %lld*%lld tiles\n", ans[i], 1LL << i, 1LL << i);
    }

    return 0;
}
