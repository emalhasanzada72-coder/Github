/*
    ---------------------------------------------------------
    |                PROJECT: 2048 GAME IN C                |
    |                Windows Terminal Version               |
    |                Author: (Your Name)                   |
    ---------------------------------------------------------

    این نسخه فقط برای ویندوز طراحی شده است.
    - استفاده از cls برای پاک کردن صفحه
    - کامنت‌های کامل برای ارائهٔ دانشگاهی
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4   // اندازه صفحه 4x4

int board[N][N];
int score = 0;

/*---------------------------------------------------------
    مقداردهی اولیه صفحه
---------------------------------------------------------*/
void init_board() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
}

/*---------------------------------------------------------
    چاپ صفحه و امتیاز
---------------------------------------------------------*/
void print_board() {
    system("cls");   // فقط ویندوز

    printf("=========== 2048 GAME (Windows) ===========\n");
    printf("Score: %d\n\n", score);

    for (int i = 0; i < N; i++) {
        printf("+------+------+------+------+ \n");
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0)
                printf("|%6c", ' ');
            else
                printf("|%6d", board[i][j]);
        }
        printf("|\n");
    }
    printf("+------+------+------+------+ \n");
}

/*---------------------------------------------------------
    شمارش خانه‌های خالی
---------------------------------------------------------*/
int empty_count() {
    int c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0)
                c++;
    return c;
}

/*---------------------------------------------------------
    اضافه کردن یک عدد جدید (۲ یا ۴)
---------------------------------------------------------*/
void add_random_tile() {
    int empties = empty_count();
    if (empties == 0) return;

    int r = rand() % empties;
    int k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                if (k == r) {
                    board[i][j] = (rand() % 10 == 0) ? 4 : 2;
                    return;
                }
                k++;
            }
        }
    }
}

/*---------------------------------------------------------
    بررسی امکان حرکت (برای Game Over)
---------------------------------------------------------*/
int can_move() {
    if (empty_count() > 0) return 1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if (board[i][j] == board[i][j + 1])
                return 1;

    for (int j = 0; j < N; j++)
        for (int i = 0; i < N - 1; i++)
            if (board[i][j] == board[i + 1][j])
                return 1;

    return 0;
}

/*---------------------------------------------------------
    چرخاندن صفحه 90 درجه ساعتگرد
---------------------------------------------------------*/
void rotate_board() {
    int tmp[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = tmp[j][N - 1 - i];
}

/*---------------------------------------------------------
    فشرده‌سازی و ادغام یک سطر به چپ
---------------------------------------------------------*/
int compress_and_merge_row(int row[N]) {
    int new_row[N] = {0};
    int idx = 0;
    int changed = 0;

    for (int i = 0; i < N; i++)
        if (row[i] != 0)
            new_row[idx++] = row[i];

    for (int i = 0; i < N - 1; i++) {
        if (new_row[i] != 0 && new_row[i] == new_row[i + 1]) {
            new_row[i] *= 2;
            score += new_row[i];
            new_row[i + 1] = 0;
            changed = 1;
        }
    }

    int final_row[N] = {0};
    idx = 0;
    for (int i = 0; i < N; i++)
        if (new_row[i] != 0)
            final_row[idx++] = new_row[i];

    for (int i = 0; i < N; i++) {
        if (row[i] != final_row[i]) {
            row[i] = final_row[i];
            changed = 1;
        }
    }

    return changed;
}

/*---------------------------------------------------------
    حرکت به چپ
---------------------------------------------------------*/
int move_left() {
    int changed = 0;
    for (int i = 0; i < N; i++)
        if (compress_and_merge_row(board[i]))
            changed = 1;
    return changed;
}

/*---------------------------------------------------------
    انجام حرکت w/a/s/d
---------------------------------------------------------*/
int move(char dir) {
    int changed = 0;

    if (dir == 'a') {
        changed = move_left();
    }
    else if (dir == 'd') {
        rotate_board();
        rotate_board();
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
    }
    else if (dir == 'w') {
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
        rotate_board();
        rotate_board();
    }
    else if (dir == 's') {
        rotate_board();
        rotate_board();
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
    }

    return changed;
}

/*---------------------------------------------------------
    تابع اصلی
---------------------------------------------------------*/
int main() {
    char c;
    srand(time(NULL));

    init_board();
    add_random_tile();
    add_random_tile();

    while (1) {
        print_board();

        if (!can_move()) {
            printf("\nGame Over! Final Score: %d\n", score);
            break;
        }

        printf("Move (w/a/s/d), q to quit: ");
        scanf(" %c", &c);

        if (c == 'q')
            break;

        if (move(c))
            add_random_tile();
    }

    return 0;
}
