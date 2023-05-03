#include "tic_tac_toe.h"
#include <stdio.h>

void initialize_Game_Board(char arr[][MAX_COLUMN]){
    int row = 0,column = 0;
    for(;row<MAX_ROW;row++){
        for(;column<MAX_COLUMN;column++){
            if(row==0||row==2||row==4){
                if(column==3||column==7){
                    arr[row][column]= '|';
                }
                else{
                    arr[row][column]= ' ';
                }
            }
            else{
                arr[row][column]= '-';
            }            
        }
        column=0;
    }    
}

void show_Game_Board(int row , int column , char array[][column]){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%c",array[i][j]);
        }
        printf("\n");
    }
}

int update_Game_Board(char arr[][MAX_COLUMN], int board_matrix[][SIZE],int turn){
    int cell;
    int arr_cell[9] = {1,2,3,4,5,6,7,8,9};
    printf("Please select a cell:");
    scanf("%d",&cell);
    while(cell<1||cell>9){
        printf("Please enter a number between 1 and 9.");
        scanf("%d",&cell);
    }
    while(1){
        int i=0;
        int check=0;
        for(;i<9;i++){
            if(cell==arr_cell[i]){
                int check=1;
                break;
            }
        }
        if(check){
            break;
        }
        else{
            printf("Enter a number that has not been selected before.");
            scanf("%d",&cell);
        }
    }
    return 1;
}

void start_Game(void){
    int user_input;
    char board[MAX_ROW][MAX_COLUMN];
    int board_matrix[SIZE][SIZE];
    initialize_Game_Board(board);
    int player_turn = 0;
    while(update_Game_Board(board,board_matrix,player_turn%2)){
        player_turn++;
    }
}
void Menu(void){
    printf("WELCOME!\nThis is a Tic-Tac-Toe\nEveryone knows how to play this game but it's my game.\n");
    char shape_of_board[MAX_SIZE] = " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n";
    printf("The first player begins with 'O'\nThen the player chooses a cell and the move passes to the other player\n");
    printf("The cell rows are as follows:\n");
    printf("%s",shape_of_board);
    printf("Press any button to start the game!\n");
    char press;
    scanf("%c",&press);
    start_Game();
}
