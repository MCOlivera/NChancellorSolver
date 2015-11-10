#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *board;
int s = 0;
int n;

int unsafe(int y){
    int t;
    int x = board[y];

    //if on the same column
    for (int i = 1; i <= y; i++){
        t = board[y-i];
        //if (t == x || t == x-i || t == x+i){

        if (t == x){
            return 1;
        }
    }

    //if could be attacked by a knight
    if (y>0){
        t = board[y-1];
        if (t == x+2 || t == x-2){
            return 1;
        }
    }

    if (y>1){
        t = board[y-2];
        if (t == x+1 || t == x-1){
            return 1;
        }
    }

    return 0;
}

void printBoard(){
    printf("\n\nSolution %d\n", s);
    for (int y=0; y<n; y++){
        for (int x=0; x<n; x++){
            if (board[y] == x){
                printf("|C");
            } else {
                printf("|_");
            }
        }
        printf("|\n");
    }
}

int main(){
    int y = 0;

    n = 8;

    board = (int *) malloc (sizeof(int) * n);

    board[0] = -1;

    while (y >= 0){
        do {
            board[y]++;
        } while((board[y] < n) && unsafe(y) == 1);

        if(board[y] < n){
            if (y < n-1){
                board[++y] = -1;
            } else {
                s++;
                printBoard();
            }
        } else {
            y--;
        }
    }

    printf("Found %d solutions!\n", s);
    return 0;
}
