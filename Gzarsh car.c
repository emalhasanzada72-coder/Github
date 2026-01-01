#include <stdio.h>
int main() {
    int x; 
    long long z;
    if (scanf("%d %lld", &x, &z) != 2) return 0;
    long long total_capacity = 0;
    int current_capacity;
    for (int i = 0; i < x; i++) {
        scanf("%d", &current_capacity);
        total_capacity += current_capacity;

    }
    if (total_capacity >= z) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
    return 0;
}