#ifndef functions
#define functions
void initializeMatrix(int *matrix, int size1, int size2);
void print_game_board(int matrix[3][3]);
void copy_matrix(int source[3][3], int destination[3][3]);
void generate_random_move(int matrix[3][3], int result[3]);
int check(int matrix[3][3]);
void player(int matrix[3][3], int player_var);
void check_winner(int matrix[3][3], int *counter_1, int player_var);
void find_critical_position(int matrix[3][3], int result[3], int player_var);
void find_strategic_position_1(int matrix[3][3], int result_1[3], int player_var);
void find_strategic_position_2(int matrix[3][3], int result_2[3], int player_var);
void oppenent_strategic_position(int matrix[3][3], int result_1[3], int player_var);
void future(int matrix[3][3], int result[3], int player_var);
void bot(int matrix[3][3], int player_var);
void bot_vs_bot();
int player_vs_bot();
int player_vs_player();
#endif