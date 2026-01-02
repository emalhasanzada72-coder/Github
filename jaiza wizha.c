#include <stdio.h>
#include <string.h>

char s[3000], st[3000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    int top = 0;
    for (int i = 0; i < n; i++) {
        while (top > 0 && k > 0 && st[top-1] < s[i]) {
            top--;
            k--;
        }
        st[top++] = s[i];
    }

    top -= k;
    st[top] = '\0';

    printf("%s", st);
    return 0;
}
