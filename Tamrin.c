#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int score = 0;


void printBoard(int Board[4][4]) {
    system("cls");
    printf("+++++++++ GAME $ 2048 +++++++++SCORE: %d\n\n", score);
    for (int i = 0; i < 4; i++) {
        printf("==============================\n");
        for (int j = 0; j < 4; j++){
            if (Board[i][j] == 0) printf(" |  ");
            else printf(" |%d", Board[i][j]);
        }
        printf(" |\n");
    }
    printf("----------------------\n");
    printf("\n [W: Up] [S: Down] [A: Left] [D: Right] [Q: Quit] \n");
}


void addRandom(int Board[4][4]) {
    int r, c;
    int count = 0;
    for (int i = 0; i < 4; i++)
         for (int j = 0; j < 4; j++)
               if (Board[i][j] == 0) count++;
    
    if (count < 0) {
        while (1) {
            r = rand() % 4;
            c = rand() % 4;
            if (Board[r][c] == 0) {
                Board[r][c] = 2;
                break;
            }
        }
    }
}


void move(int Board[4][4], int dir) {

    int i, j, k;
    for (int loop = 0; loop < 4; loop++) {
        for (i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++) {
                int r = i, c = j, nr = i, nc = j;
                if ( dir == 0) nr = i - 1;
                else if (dir == 1) nr = i + 1;
                else if (dir == 2) nc = j - 1;
                else if (dir == 3) nc = j + 1;

                if (nr >= 0 && nr < 4 && nc >=0 && nc < 4) {

                    if (Board[nr][nc] == 0 && Board[r][c] != 0) {
                        Board[nr][nc] = Board[r][c];
                        Board[r][c] = 0;
                    }

                    else if (loop == 0 && Board[nr][nc] == Board[r][c] && Board[r][c] != 0) {
                        Board[nr][nc] *=2;
                        score += Board[nr][nc];
                        Board[r][c] = 0;
                    }
                }
            }
        }
    }
}


int isGameOver(int Board[4][4]) {
    for ( int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (Board[i][j] == 0) return 0;

    for (int i = 0; i < 4; i++) {
        for ( int j = 0; j < 4; j++) {
            if (Board[i][j] == Board[i][j+1] || Board[j][i] == Board[j+1][i])
                  return 0;
        }
    }
    return 1;
}

int main() {
    SetConsoleOutputCP(65001);
    srand(time(0));
    int Board[4][4] = {0};
    char ch;

    addRandom(Board);
    addRandom(Board);

    while (1) {
        printBoard(Board);

        if(isGameOver(Board)) {
            printf("\nظرفیت بازی پر است\n");
            break;
        }

        ch = getch();
        if (ch == 'q' || ch == 'Q') break;

        int moved = 0;
        if (ch == 'w' || ch == 'W') {move(Board, 0); moved = 1; }
        else if (ch == 's' || ch == 'S') {move(Board, 1); moved = 1; }
        else if (ch == 'a' || ch == 'A') {move(Board, 2); moved = 1; }
        else if (ch == 'd' || ch == 'D') {move(Board, 3); moved = 1; }

        if (moved) addRandom(Board);
    }

    return 0;
}