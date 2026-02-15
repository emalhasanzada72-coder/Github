#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int score = 0;

// نمایش جدول و امتیاز
void printBoard(int Board[4][4]) {
    system("cls");
    printf("==== 2048 GAME ====   Score: %d\n\n", score);
    for (int i = 0; i < 4; i++) {
        printf("-------------------------\n");
        for (int j = 0; j < 4; j++) {
            if (Board[i][j] == 0)
                printf("|    ");
            else
                printf("|%4d", Board[i][j]);
        }
        printf(" |\n");
    }
    printf("-------------------------\n");
    printf("\n[W: Up] [S: Down] [A: Left] [D: Right] [Q: Quit]\n");
}

// اضافه کردن عدد تصادفی 2 یا 4
void addRandom(int Board[4][4]) {
    int a, b;
    int count = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (Board[i][j] == 0) count++;

    if (count > 0) {
        while (1) {
            a = rand() % 4;
            b = rand() % 4;
            if (Board[a][b] == 0) {
                Board[a][b] = (rand() % 10 == 0) ? 4 : 2;
                break;
            }
        }
    }
}

// حرکت و ادغام
void move(int Board[4][4], int dir) {
    int i, j;
    for (int loop = 0; loop < 3; loop++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                int a = i, b = j, na = i, nb = j;
                if (dir == 0) na = i - 1;        // up
                else if (dir == 1) na = i + 1;   // down
                else if (dir == 2) nb = j - 1;   // left
                else if (dir == 3) nb = j + 1;   // right

                if (na >= 0 && na < 4 && nb >= 0 && nb < 4) {
                    // حرکت به خانه خالی
                    if (Board[na][nb] == 0 && Board[a][b] != 0) {
                        Board[na][nb] = Board[a][b];
                        Board[a][b] = 0;
                    }
                    // ادغام صحیح
                    else if (Board[na][nb] == Board[a][b] && Board[a][b] != 0) {
                        Board[na][nb] *= 2;
                        score += Board[na][nb];
                        Board[a][b] = 0;
                    }
                }
            }
        }
    }
}

// بررسی پایان بازی
int isGameOver(int Board[4][4]) {
    // خانه خالی یعنی بازی ادامه دارد
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (Board[i][j] == 0)
                return 0;

    // بررسی ادغام افقی
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (Board[i][j] == Board[i][j + 1])
                return 0;

    // بررسی ادغام عمودی
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 3; i++)
            if (Board[i][j] == Board[i + 1][j])
                return 0;

    // هیچ حرکت و ادغامی ممکن نیست → Game Over
    return 1;
}

int main() {
    SetConsoleOutputCP(65001); // پشتیبانی UTF-8 برای فارسی
    srand(time(0));

    int Board[4][4] = {0};
    char ch;

    addRandom(Board);
    addRandom(Board);

    while (1) {
        printBoard(Board);

        if (isGameOver(Board)) {
            printf("\nبازی تمام شد! ظرفیت بازی پر است.\n");
            break;
        }

        ch = getch();
        if (ch == 'q' || ch == 'Q') break;

        int moved = 0;
        if (ch == 'w' || ch == 'W') { move(Board, 0); moved = 1; }
        else if (ch == 's' || ch == 'S') { move(Board, 1); moved = 1; }
        else if (ch == 'a' || ch == 'A') { move(Board, 2); moved = 1; }
        else if (ch == 'd' || ch == 'D') { move(Board, 3); moved = 1; }

        if (moved) addRandom(Board);
    }

    return 0;
}
