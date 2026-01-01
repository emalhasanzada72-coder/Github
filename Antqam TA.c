#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long dp[30] = {0};
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i +=2)
    dp[i] = 4 * dp[i - 2] - dp[i - 4];
    long long ans = (n % 2 == 1 ? 0 : dp[n]);
    printf("%lld", ans * 2);
    return 0; 
}