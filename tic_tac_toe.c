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
int check_for_Win(int board[][SIZE],int sg){
    if (board[0][0] == sg && board[0][1] == sg && board[0][2] == sg ||
      board[1][0] == sg && board[1][1] == sg && board[1][2] == sg ||
      board[2][0] == sg && board[2][1] == sg && board[2][2] == sg){
        return 1;
    }
    else if (board[0][0] == sg && board[1][0] == sg && board[2][0] == sg ||
           board[0][1] == sg && board[1][1] == sg && board[2][1] == sg ||
           board[0][2] == sg && board[1][2] == sg && board[2][2] == sg){
        return 1;
    }
    else if (board[0][0] == sg && board[1][1] == sg && board[2][2] == sg ||
           board[0][2] == sg && board[1][1] == sg && board[2][0] == sg){
        return 1;
    }
    return 0;
}
int update_Game_Board(char arr[][MAX_COLUMN], int board_matrix[][SIZE],int arr_cell[],int turn){
    int cell;
    char player_sing;
    printf("Player %d turns.\n",turn+1);
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
                check=1;
                break;
            }
        }
        if(check==1){
            arr_cell[i]=0;
            break;
        }
        else{
            printf("Enter a number that has not been selected before.");
            scanf("%d",&cell);
        }
    }
    if(turn==1){player_sing='X';}
    else{player_sing='O';}
    switch (cell)
    {
    case 1:
        arr[0][1]=player_sing;
        board_matrix[0][0]= turn;
        break;
    case 2:
        arr[0][5]=player_sing;
        board_matrix[0][1]= turn;
        break;
    case 3:
        arr[0][9]=player_sing;
        board_matrix[0][2]= turn;
        break;
    case 4:
        arr[2][1]=player_sing;
        board_matrix[1][0]= turn;
        break;
    case 5:
        arr[2][5]=player_sing;
        board_matrix[1][1]= turn;
        break;
    case 6:
        arr[2][9]=player_sing;
        board_matrix[1][2]= turn;
        break;
    case 7:
        arr[4][1]=player_sing;
        board_matrix[2][0]= turn;
        break;
    case 8:
        arr[4][5]=player_sing;
        board_matrix[2][1]= turn;
        break;
    case 9:
        arr[4][9]=player_sing;
        board_matrix[2][2]= turn;
        break;
    default:
        break;
    }

    return 1;
}

void start_Game(void){
    int user_input;
    char board[MAX_ROW][MAX_COLUMN];
    int board_matrix[SIZE][SIZE]={{9,9,9},
                                  {9,9,9},
                                  {9,9,9}};
    int arr_cell[9] = {1,2,3,4,5,6,7,8,9};
    initialize_Game_Board(board);
    int player_turn = 0;
    while(player_turn<9){
        if(check_for_Win(board_matrix,player_turn%2)){
            printf("   ### Player %d Won ###",player_turn%2+1);
            break;
        }
        update_Game_Board(board,board_matrix,arr_cell,player_turn%2);
        show_Game_Board(MAX_ROW,MAX_COLUMN,board);
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
