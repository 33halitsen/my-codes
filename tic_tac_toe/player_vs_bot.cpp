#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int player_vs_bot()
{
    int matrix[3][3], counter_1 = 0, result[3];

    initializeMatrix(&matrix[0][0], 3, 3);

    for (int i = 0; i < 10; i++)
    {
        print_game_board(matrix);
        player(matrix, 2);
        check_winner(matrix, &counter_1, 2);
        if (counter_1 > 0)
        {
            print_game_board(matrix);
            printf("player wins");
            return 2;
        }
        i++;
        print_game_board(matrix);
        bot(matrix, 1);

        check_winner(matrix, &counter_1, 1);
        if (counter_1 > 0)
        {
            print_game_board(matrix);
            printf("bot wins");
            return 1;
        }
        if (i == 9)
        {
            print_game_board(matrix);
            break;
        }
    }

    return 0;
}
