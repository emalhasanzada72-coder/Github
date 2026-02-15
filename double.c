#include <stdio.h>
int main() {
    int target = 25;
    int guess;
    int chances = 5;
    printf(" welcom to hads bazy");
    printf("man yak adad dr zhn khode darm hds bzn\n", chances);
    for (int i = 1; i < chances; i++) {
        printf(" hads tow chist %d");
        scanf("%d", &guess);
        if (guess == target) {
            printf(" hads shma drst bod %d\n", target);
            break;
        }
        else if (guess < target) {
            printf("addad man kochakter ast payyen t\n");
        }
        if (i== chances){
            printf("matasfaneh bakhited addad man bod%d\n", target);
        }
    }
    return 0;
}