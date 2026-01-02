#include <stdio.h>

long long a[200005];

int main() {
    int n, m;
    long long k;
    scanf("%d %d %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for (int s = n; s >= 1; s--) {
        long long cap = k;
        int box = 1, ok = 1;
        for (int i = s; i <= n; i++) {
            if (a[i] > cap) {
                if (++box > m) { ok = 0; break; }
                cap = k;
            }
            cap -= a[i];
        }
        if (ok) {
            printf("%d", n - s + 1);
            return 0;
        }
    }
}
