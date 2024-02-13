#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void bot_vs_bot()
{
    int matrix[3][3], counter_1 = 0;
    initializeMatrix(&matrix[0][0], 3, 3); // Initialize the entire game matrix with empty spaces, i.e., 0 values

    for (int i = 0; i < 10; i++)
    {
        print_game_board(matrix);            // Print the game matrix
        bot(matrix, 1);                      // Make a move for bot 1
        check_winner(matrix, &counter_1, 1); // Check if bot 1 made a winning move
        if (counter_1 > 0)
        {
            print_game_board(matrix);
            printf("bot_1 wins");
            return;
        }
        i++;                                 // Increment the move counter
        print_game_board(matrix);            // Print the game matrix
        bot(matrix, 2);                      // Make a move for bot 2
        check_winner(matrix, &counter_1, 2); // Check if bot 2 made a winning move
        if (counter_1 > 0)
        {
            print_game_board(matrix);
            printf("bot_2 wins");
            return;
        }
        if (i == 9) // Check if a total of 9 moves have been made after the bot's move
        {
            print_game_board(matrix);
            return;
        }
    }

    return;
}
