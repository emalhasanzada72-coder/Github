#include <stdio.h>

int main() {
    int a;
    if (scanf("%d", &a) != 1) return 0;
    if (a <= 1) {
        int temp;
        for (int i = 0; i < a; i++) scanf("%d", &temp);
        printf("0\n");
        return 0;
    }

    int current_status, last_status;
    int changes = 0;
    scanf("%d", &last_status);
    for (int i = 1; i < a; i++) {
        scanf("%d", &current_status);
        
        if (current_status != last_status) {
            changes++;
        }
        last_status = current_status;
    }
    printf("%d\n", changes);

    return 0;
}