#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int board[N][N];
int score = 0;

void init_board() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
}

void print_board() {
    system("clear"); // روی ویندوز اگر خواستی "cls" بگذار
    printf("2048 Game (w/a/s/d + Enter)   Score: %d\n\n", score);
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

int empty_count() {
    int c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0)
                c++;
    return c;
}

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

void rotate_board() {
    int tmp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = tmp[j][N - 1 - i];
}

int compress_and_merge_row(int row[N]) {
    int new_row[N] = {0};
    int idx = 0;
    int changed = 0;

    // فشرده‌سازی (حذف صفرها)
    for (int i = 0; i < N; i++) {
        if (row[i] != 0) {
            new_row[idx++] = row[i];
        }
    }

    // ادغام
    for (int i = 0; i < N - 1; i++) {
        if (new_row[i] != 0 && new_row[i] == new_row[i + 1]) {
            new_row[i] *= 2;
            score += new_row[i];
            new_row[i + 1] = 0;
            changed = 1;
        }
    }

    // دوباره فشرده‌سازی
    int final_row[N] = {0};
    idx = 0;
    for (int i = 0; i < N; i++) {
        if (new_row[i] != 0) {
            final_row[idx++] = new_row[i];
        }
    }

    // بررسی تغییر
    for (int i = 0; i < N; i++) {
        if (row[i] != final_row[i]) {
            changed = 1;
            row[i] = final_row[i];
        }
    }

    return changed;
}

int move_left() {
    int changed = 0;
    for (int i = 0; i < N; i++) {
        if (compress_and_merge_row(board[i]))
            changed = 1;
    }
    return changed;
}

int move(char dir) {
    int changed = 0;

    // جهت‌دهی با چرخاندن ماتریس
    // 'a' = چپ، 'd' = راست، 'w' = بالا، 's' = پایین
    if (dir == 'a') {
        changed = move_left();
    } else if (dir == 'd') {
        // راست: سه بار چرخش + حرکت چپ + یک بار چرخش
        rotate_board();
        rotate_board();
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
    } else if (dir == 'w') {
        // بالا: یک بار چرخش + حرکت چپ + سه بار چرخش
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
        rotate_board();
        rotate_board();
    } else if (dir == 's') {
        // پایین: سه بار چرخش + حرکت چپ + یک بار چرخش
        rotate_board();
        rotate_board();
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
    }

    return changed;
}

int main() {
    char c;
    srand((unsigned int)time(NULL));

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
        if (scanf(" %c", &c) != 1) break;
        if (c == 'q') break;

        if (c == 'w' || c == 'a' || c == 's' || c == 'd') {
            if (move(c)) {
                add_random_tile();
            }
        }
    }

    return 0;
}
