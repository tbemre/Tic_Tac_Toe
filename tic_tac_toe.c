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