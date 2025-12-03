#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX 20

// ================= COLORS =================
void setColor(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

// ================= CLEAR SCREEN =================
// Full clear for menus and end screens
void fullClearScreen() {
    system("cls");
}

// Smooth redraw for game loop (no blink)
void clearScreen() {
    COORD coord = {0, 0};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, coord);
}

// ================= DISPLAY MAZE =================
void displayMaze(char maze[MAX][MAX], int r, int c, int timeLeft) {
    clearScreen();

    printf("============================================\n");
    printf("             MAZE ESCAPE GAME\n");
    printf("============================================\n");
    printf("Objective: Help B reach G\n");
    printf("Time Remaining: %d seconds\n\n", timeLeft);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(maze[i][j] == 'B') setColor(1);   // Blue
            else if(maze[i][j] == 'G') setColor(5); // Pink
            else setColor(7); // White

            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    setColor(7);
}

// ================= LOAD MAZE =================
void loadMaze(int mode, char maze[MAX][MAX], int *r, int *c, int *px, int *py, int *timeLimit) {

    if(mode == 1) { // EASY
        *r = 8; *c = 8; *timeLimit = 50;

        char easy[8][8] = {
            {'#','#','#','#','#','#','#','#'},
            {'#','B',' ','#',' ',' ',' ','#'},
            {'#',' ',' ','#',' ','#',' ','#'},
            {'#',' ','#','#',' ','#',' ','#'},
            {'#',' ',' ',' ',' ','#',' ','#'},
            {'#','#','#',' ','#','#',' ','#'},
            {'#',' ',' ',' ',' ',' ','G','#'},
            {'#','#','#','#','#','#','#','#'}
        };

        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++) {
                maze[i][j] = easy[i][j];
                if(maze[i][j] == 'B') { *px = i; *py = j; }
            }
    }

    else if(mode == 2) { // MEDIUM
        *r = 12; *c = 12; *timeLimit = 35;

        char med[12][12] = {
            {'#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#','B',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
            {'#',' ','#','#',' ','#','#','#',' ','#',' ','#'},
            {'#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#'},
            {'#',' ','#','#','#',' ','#',' ','#','#',' ','#'},
            {'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#'},
            {'#','#','#',' ','#','#','#',' ','#','#','#','#'},
            {'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
            {'#',' ','#','#','#',' ','#','#','#','#',' ','#'},
            {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','G',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#'}
        };

        for(int i=0;i<12;i++)
            for(int j=0;j<12;j++) {
                maze[i][j] = med[i][j];
                if(maze[i][j] == 'B') { *px = i; *py = j; }
            }
    }

    else { // HARD
        *r = 15; *c = 15; *timeLimit = 25;

        char hard[15][15] = {
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#','B',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
            {'#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#'},
            {'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#'},
            {'#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#'},
            {'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
            {'#','#','#',' ','#','#','#',' ','#','#','#',' ','#','#','#'},
            {'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#'},
            {'#',' ','#','#','#',' ','#','#','#','#','#',' ','#',' ','#'},
            {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#'},
            {'#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#'},
            {'#',' ','#','#','#','#',' ','#','#','#','#',' ','#',' ','#'},
            {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','G','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
        };

        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++) {
                maze[i][j] = hard[i][j];
                if(maze[i][j] == 'B') { *px = i; *py = j; }
            }
    }
}

// ================= MAIN =================
int main() {

    int mode;

RESTART:
    fullClearScreen();   // full clear for menu
    printf("============================================\n");
    printf("              MAZE ESCAPE GAME\n");
    printf("============================================\n");
    printf("Objective: Help B reach G\n\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("\nChoose your mode: ");
    scanf("%d", &mode);

    if(mode < 1 || mode > 3) {
        printf("\nInvalid choice! Press any key...");
        getch();
        goto RESTART;
    }

    char maze[MAX][MAX];
    int r,c,px,py,timeLimit;
    loadMaze(mode, maze, &r, &c, &px, &py, &timeLimit);

    time_t start = time(NULL);

    while(1) {
        int elapsed = (int)difftime(time(NULL), start);
        int remaining = timeLimit - elapsed;

        if(remaining <= 0) {
            fullClearScreen();
            printf("=========== GAME OVER ==========\n\n");
            printf("You ran out of time.\n");
            printf("Try again to reach the goal!\n\n");
            printf("Press R to Restart\n");
            printf("Press any other key to Exit\n");

            char ch = getch();
            if(ch == 'r' || ch == 'R') goto RESTART;
            else break;  // exit loop gracefully
        }

        displayMaze(maze, r, c, remaining);

        int ch = 0;
        if(_kbhit()) {
            ch = getch();
            if(ch == 0 || ch == 224) ch = getch();
        }

        int nx = px, ny = py;

        if(ch == 72 || ch == 'w' || ch == 'W') nx--;
        if(ch == 80 || ch == 's' || ch == 'S') nx++;
        if(ch == 75 || ch == 'a' || ch == 'A') ny--;
        if(ch == 77 || ch == 'd' || ch == 'D') ny++;

        if(nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] != '#') {

            if(maze[nx][ny] == 'G') {
                fullClearScreen();
                printf("=========== SUCCESS! ===========\n\n");
                printf("Hooray!\n");
                printf("You are a Matchmaker!\n\n");
                printf("Time Taken: %d seconds\n\n", elapsed);
                printf("Press R to Restart\n");
                printf("Press any other key to Exit\n");

                char ch2 = getch();
                if(ch2 == 'r' || ch2 == 'R') goto RESTART;
                else break;  // exit loop gracefully
            }

            maze[px][py] = ' ';
            px = nx;
            py = ny;
            maze[px][py] = 'B';
        }

        Sleep(100);
    }

    return 0;
}
