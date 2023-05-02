#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
#define MAX_COLUMN 12
#define MAX_ROW 5
void print_all_array(int row , int column , char array[][column]);
void initialize_Game_Board(int size,char arr[][MAX_COLUMN]);
int update_Game_Board(void);
void show_Game_Board(void);
int check_for_Win(void);
void start_Game(void);
#endif