#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4   // اندازه صفحه 4x4

// اگر روی ویندوزی، این ماکرو خودش دستور درست پاک کردن صفحه را انتخاب می‌کند
#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

// ماتریس بازی
int board[N][N];
// امتیاز
int score = 0;

/*---------------------------------------------------------
  مقداردهی اولیه کل صفحه به صفر
---------------------------------------------------------*/
void init_board() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
}

/*---------------------------------------------------------
  چاپ صفحه بازی
---------------------------------------------------------*/
void print_board() {
    system(CLEAR_CMD);  // پاک کردن صفحه (در ویندوز = cls ، در لینوکس = clear)

    printf("=== 2048 GAME ===   Score: %d\n\n", score);

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
  شمارش تعداد خانه‌های خالی
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
  اضافه کردن یک عدد جدید (۲ یا ۴) در یکی از خانه‌های خالی
---------------------------------------------------------*/
void add_random_tile() {
    int empties = empty_count();
    if (empties == 0) return;

    int r = rand() % empties; // انتخاب اندیس تصادفی بین خانه‌های خالی
    int k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                if (k == r) {
                    // 90٪ احتمال 2 ، 10٪ احتمال 4
                    board[i][j] = (rand() % 10 == 0) ? 4 : 2;
                    return;
                }
                k++;
            }
        }
    }
}

/*---------------------------------------------------------
  آیا حرکت دیگری ممکن است یا نه؟ (برای Game Over)
---------------------------------------------------------*/
int can_move() {
    // اگر حداقل یک خانه خالی هست ⇒ می‌شود حرکت کرد
    if (empty_count() > 0) return 1;

    // اگر دو خانهٔ افقی کنار هم برابر باشند ⇒ می‌شود حرکت کرد
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if (board[i][j] == board[i][j + 1])
                return 1;

    // اگر دو خانهٔ عمودی کنار هم برابر باشند ⇒ می‌شود حرکت کرد
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N - 1; i++)
            if (board[i][j] == board[i + 1][j])
                return 1;

    // هیچ راهی برای حرکت نیست
    return 0;
}

/*---------------------------------------------------------
  چرخاندن ماتریس 90 درجه در جهت ساعت
  برای این که همهٔ حرکت‌ها را به حرکت "چپ" تبدیل کنیم
---------------------------------------------------------*/
void rotate_board() {
    int tmp[N][N];

    // کپی کردن
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[i][j] = board[i][j];

    // چرخش: خانهٔ (i,j) جدید ← قدیم (j, N-1-i)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = tmp[j][N - 1 - i];
}

/*---------------------------------------------------------
  فشرده‌سازی و ادغام یک سطر به سمت چپ
  مثلاً: [2,0,2,4] → [4,4,0,0]
---------------------------------------------------------*/
int compress_and_merge_row(int row[N]) {
    int new_row[N] = {0};
    int idx = 0;
    int changed = 0;

    // 1) فشرده‌سازی: صفرها را حذف کن و اعداد را به چپ بچسبان
    for (int i = 0; i < N; i++) {
        if (row[i] != 0) {
            new_row[idx++] = row[i];
        }
    }

    // 2) ادغام خانه‌های برابر متوالی
    for (int i = 0; i < N - 1; i++) {
        if (new_row[i] != 0 && new_row[i] == new_row[i + 1]) {
            new_row[i] *= 2;          // دو برابر کردن
            score += new_row[i];      // اضافه کردن به امتیاز
            new_row[i + 1] = 0;       // خانهٔ بعدی را صفر کن
            changed = 1;
        }
    }

    // 3) دوباره فشرده‌سازی بعد از ادغام
    int final_row[N] = {0};
    idx = 0;
    for (int i = 0; i < N; i++) {
        if (new_row[i] != 0) {
            final_row[idx++] = new_row[i];
        }
    }

    // 4) انتقال نتیجه به آرایهٔ اصلی سطر و تشخیص تغییر
    for (int i = 0; i < N; i++) {
        if (row[i] != final_row[i]) {
            changed = 1;
            row[i] = final_row[i];
        }
    }

    return changed;
}

/*---------------------------------------------------------
  حرکت کل صفحه به سمت چپ
---------------------------------------------------------*/
int move_left() {
    int changed = 0;
    for (int i = 0; i < N; i++) {
        if (compress_and_merge_row(board[i]))
            changed = 1;
    }
    return changed;
}

/*---------------------------------------------------------
  انجام حرکت w / a / s / d
  با استفاده از چرخاندن صفحه و استفاده از move_left
---------------------------------------------------------*/
int move(char dir) {
    int changed = 0;

    if (dir == 'a') {
        // چپ
        changed = move_left();
    } else if (dir == 'd') {
        // راست: سه بار چرخش + left + یک بار چرخش
        rotate_board();
        rotate_board();
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
    } else if (dir == 'w') {
        // بالا: یک بار چرخش + left + سه بار چرخش
        rotate_board();
        if (move_left()) changed = 1;
        rotate_board();
        rotate_board();
        rotate_board();
    } else if (dir == 's') {
        // پایین: سه بار چرخش + left + یک بار چرخش
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

    // تنظیم seed برای اعداد تصادفی
    srand((unsigned int)time(NULL));

    // صفحهٔ اولیه
    init_board();
    add_random_tile();
    add_random_tile();

    while (1) {
        print_board();

        // اگر دیگر نمی‌شود حرکت کرد → Game Over
        if (!can_move()) {
            printf("\nGame Over! Final Score: %d\n", score);
            break;
        }

        printf("Move (w/a/s/d), q to quit: ");
        if (scanf(" %c", &c) != 1)
            break;

        if (c == 'q')  // خروج از بازی
            break;

        if (c == 'w' || c == 'a' || c == 's' || c == 'd') {
            // اگر حرکت معتبر بود و واقعاً تغییری ایجاد کرد،
            // یک عدد تصادفی جدید هم اضافه می‌کنیم
            if (move(c)) {
                add_random_tile();
            }
        }
        // اگر کلید نامعتبر بود، حلقه ادامه پیدا می‌کند و صفحه دوباره چاپ می‌شود
    }

    return 0;
}
