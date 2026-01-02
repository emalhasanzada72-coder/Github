#include <stdio.h>

long long a[200005], cur[200005];
int parent[200005];
int n, q;

int find(int x) {
    if (x > n) return n + 1;
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        parent[i] = i;
        cur[i] = 0;
    }
    parent[n + 1] = n + 1;

    while (q--) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            long long x;
            int p;
            scanf("%d %lld", &p, &x);

            int i = find(p);
            while (i <= n && x > 0) {
                long long space = a[i] - cur[i];
                if (space >= x) {
                    cur[i] += x;
                    x = 0;
                } else {
                    cur[i] = a[i];
                    x -= space;
                    parent[i] = find(i + 1);
                }
                i = find(i);
            }
        } else {
            int k;
            scanf("%d", &k);
            printf("%lld\n", cur[k]);
        }
    }

    return 0;
}
