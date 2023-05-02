#include <stdio.h>
#include "tic_tac_toe.h"
int main(){
    char board[MAX_ROW][MAX_COLUMN];
    char shape_of_board[MAX_SIZE] = " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n";
    printf("%s",shape_of_board);
    initialize_Game_Board(board);
    show_Game_Board(MAX_ROW,MAX_COLUMN,board);
    return 0;
}