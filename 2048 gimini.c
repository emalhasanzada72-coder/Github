/*
    پروژه بازی ۲۰۴۸
    درس برنامه‌سازی سیستم - دانشگاه ...
    نویسنده: [نام شما]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int matris[SIZE][SIZE];
int emtiyaz = 0;

// تابع برای صفر کردن تمام خانه‌های جدول در شروع بازی
void amade_sazi() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matris[i][j] = 0;
}

// نمایش جدول در کنسول
void namayesh_jadval() {
    system("cls"); // پاک کردن صفحه برای ویندوز

    printf("--- BAZI 2048 ---\n");
    printf("Emtiyaz Shoma: %d\n\n", emtiyaz);

    for (int i = 0; i < SIZE; i++) {
        printf("-----------------------------\n");
        for (int j = 0; j < SIZE; j++) {
            if (matris[i][j] == 0)
                printf("|      ");
            else
                printf("| %4d ", matris[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

// شمردن خانه‌های خالی برای پیدا کردن جای عدد جدید
int khane_haye_khali() {
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matris[i][j] == 0) count++;
    return count;
}

// اضافه کردن عدد ۲ یا ۴ به صورت رندوم در یک جای خالی
void add_adad_jadid() {
    int khali = khane_haye_khali();
    if (khali == 0) return;

    int r = rand() % khali;
    int k = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matris[i][j] == 0) {
                if (k == r) {
                    matris[i][j] = (rand() % 10 == 0) ? 4 : 2;
                    return;
                }
                k++;
            }
        }
    }
}

// چرخاندن ماتریس (برای اینکه فقط یک کد برای حرکت به چپ بنویسیم)
void charkhesh() {
    int temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = matris[i][j];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matris[i][j] = temp[j][SIZE - 1 - i];
}

// منطق اصلی حرکت به سمت چپ و ادغام اعداد
int harkat_be_chap(int radif[SIZE]) {
    int jadid[SIZE] = {0};
    int j = 0;
    int taghyir = 0;

    for (int i = 0; i < SIZE; i++)
        if (radif[i] != 0) jadid[j++] = radif[i];

    for (int i = 0; i < SIZE - 1; i++) {
        if (jadid[i] != 0 && jadid[i] == jadid[i + 1]) {
            jadid[i] *= 2;
            emtiyaz += jadid[i];
            jadid[i + 1] = 0;
            taghyir = 1;
        }
    }

    int nahaee[SIZE] = {0};
    j = 0;
    for (int i = 0; i < SIZE; i++)
        if (jadid[i] != 0) nahaee[j++] = jadid[i];

    for (int i = 0; i < SIZE; i++) {
        if (radif[i] != nahaee[i]) {
            radif[i] = nahaee[i];
            taghyir = 1;
        }
    }
    return taghyir;
}

// مدیریت جهت‌ها با استفاده از چرخش و حرکت به چپ
int anjam_harkat(char jahat) {
    int ok = 0;
    if (jahat == 'a') { // چپ
        for (int i = 0; i < SIZE; i++) if (harkat_be_chap(matris[i])) ok = 1;
    } 
    else if (jahat == 'd') { // راست
        charkhesh(); charkhesh();
        for (int i = 0; i < SIZE; i++) if (harkat_be_chap(matris[i])) ok = 1;
        charkhesh(); charkhesh();
    } 
    else if (jahat == 'w') { // بالا
        charkhesh(); charkhesh(); charkhesh();
        for (int i = 0; i < SIZE; i++) if (harkat_be_chap(matris[i])) ok = 1;
        charkhesh();
    } 
    else if (jahat == 's') { // پایین
        charkhesh();
        for (int i = 0; i < SIZE; i++) if (harkat_be_chap(matris[i])) ok = 1;
        charkhesh(); charkhesh(); charkhesh();
    }
    return ok;
}

int main() {
    char dokme;
    srand(time(NULL));

    printf("Khosh Amadid be Bazi 2048!\n");
    printf("Baraye shoru yek kelid ra bezanid...");
    getchar();

    amade_sazi();
    add_adad_jadid();
    add_adad_jadid();

    while (1) {
        namayesh_jadval();
        printf("Harkat (w/a/s/d) ya 'q' baraye khoruj: ");
        scanf(" %c", &dokme);

        if (dokme == 'q') break;

        if (anjam_harkat(dokme)) {
            add_adad_jadid();
        }
    }

    printf("\nBazi Tamam Shod! Emtiyaz: %d\n", emtiyaz);
    return 0;
}