#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int board[SIZE][SIZE];
int score = 0;

// تابع مقداردهی اولیه
void initialize_game() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;
    score = 0;
}

// نمایش جدول با فرمت تمیز
void print_board() {
    system("cls"); // در ویندوز cls و در لینوکس clear
    printf("\n--- PROJECT 2048 - UNIVERSITY ASSIGNMENT ---\n");
    printf("Score: %d\n\n", score);
    for (int i = 0; i < SIZE; i++) {
        printf("+------+------+------+------+\n");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf("|      ");
            else
                printf("| %4d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("+------+------+------+------+\n");
    printf("Controls: W (Up), S (Down), A (Left), D (Right) | Q: Quit\n");
}

// پیدا کردن تعداد خانه‌های خالی
int count_empty() {
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0) count++;
    return count;
}

// اضافه کردن عدد جدید (90% احتمال عدد 2 و 10% عدد 4)
void add_random() {
    int empty_cells = count_empty();
    if (empty_cells == 0) return;

    int target = rand() % empty_cells;
    int current = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                if (current == target) {
                    board[i][j] = (rand() % 10 == 0) ? 4 : 2;
                    return;
                }
                current++;
            }
        }
    }
}

// چرخاندن ماتریس (تکنیک اصلی برای کاهش حجم کد)
void rotate_board() {
    int temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[j][SIZE - 1 - i] = board[i][j];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = temp[i][j];
}

// منطق حرکت سطر به سمت چپ
int move_left() {
    int moved = 0;
    for (int i = 0; i < SIZE; i++) {
        int new_row[SIZE] = {0};
        int pos = 0;

        // 1. فشرده‌سازی (حذف صفرها)
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {
                new_row[pos++] = board[i][j];
            }
        }

        // 2. ادغام اعداد مشابه
        for (int j = 0; j < SIZE - 1; j++) {
            if (new_row[j] != 0 && new_row[j] == new_row[j + 1]) {
                new_row[j] *= 2;
                score += new_row[j];
                new_row[j + 1] = 0;
                moved = 1;
            }
        }

        // 3. فشرده‌سازی مجدد بعد از ادغام
        int final_row[SIZE] = {0};
        int final_pos = 0;
        for (int j = 0; j < SIZE; j++) {
            if (new_row[j] != 0) {
                final_row[final_pos++] = new_row[j];
            }
        }

        // بررسی تغییر برای برگرداندن به تابع اصلی
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != final_row[j]) {
                board[i][j] = final_row[j];
                moved = 1;
            }
        }
    }
    return moved;
}

// اعمال حرکت بر اساس ورودی
int apply_move(char action) {
    int success = 0;
    switch (action) {
        case 'a': // Left
            success = move_left();
            break;
        case 'd': // Right (2 rotation)
            rotate_board(); rotate_board();
            success = move_left();
            rotate_board(); rotate_board();
            break;
        case 'w': // Up (3 rotation)
            rotate_board(); rotate_board(); rotate_board();
            success = move_left();
            rotate_board();
            break;
        case 's': // Down (1 rotation)
            rotate_board();
            success = move_left();
            rotate_board(); rotate_board(); rotate_board();
            break;
    }
    return success;
}

// چک کردن باخت
int is_game_over() {
    if (count_empty() > 0) return 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j + 1]) return 0; // افقی
            if (board[j][i] == board[j + 1][i]) return 0; // عمودی
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char input;
    
    initialize_game();
    add_random();
    add_random();

    while (1) {
        print_board();
        
        if (is_game_over()) {
            printf("\nGAME OVER! Final Score: %d\n", score);
            break;
        }

        printf("Enter move: ");
        scanf(" %c", &input); // فاصله قبل %c برای مدیریت بافر کیبورد

        if (input == 'q' || input == 'Q') break;

        // تبدیل حروف بزرگ به کوچک (اختیاری برای راحتی بازیکن)
        if (input >= 'A' && input <= 'Z') input += 32;

        if (apply_move(input)) {
            add_random();
        }
    }

    return 0;
}