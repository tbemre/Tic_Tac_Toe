#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
#define MAX_COLUMN 11
#define MAX_ROW 5
#define MAX_SIZE 61
#define SIZE 3
void initialize_Game_Board(char arr[][MAX_COLUMN]);
int update_Game_Board(char arr[][MAX_COLUMN], int board_matrix[SIZE][SIZE],int arr_cell[],int turn);
void show_Game_Board(int row , int column , char array[][column]);
int check_for_Win(void);
void start_Game(void);
void Menu(void);
#endif