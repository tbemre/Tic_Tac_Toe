#include <stdio.h>
#include "tic_tac_toe.h"
#define SIZE 3
#define MAX_SIZE 61
#define MAX_COLUMN 12
#define MAX_ROW 5
int main(){
    char board[MAX_ROW][MAX_COLUMN];
    char shape_of_board[MAX_SIZE] = " X | O | X \n-----------\n O | X | O \n-----------\n X | O | X \n";
    initialize_Game_Board(SIZE,board);
    print_all_array(MAX_ROW,MAX_COLUMN,&board);
    return 0;
}