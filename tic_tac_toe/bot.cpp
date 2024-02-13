#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void bot(int matrix[3][3], int player_var)
{
    if (check(matrix) == 0)
    {
        return;
    }
    /* The "usernot" variable is adjusted to be the opposite of the "player_var" parameter, i.e., 1 becomes 2, and 2 becomes 1. */
    int player_var_not = 3 - player_var;

    if (matrix[1][1] == 0)
    {
        matrix[1][1] = player_var;
        return;
    }
    // The "result" array is used to get suitable indices from the position functions.
    int result[3] = {0, 0, 0};
    // Check if the current player has a chance to win.
    find_critical_position(matrix, result, player_var);

    if (result[0] > 0)
    {
        matrix[result[1]][result[2]] = player_var;
        return;
    }
    // Check if the opponent has a chance to win.
    find_critical_position(matrix, result, player_var_not);

    if (result[0] > 0)
    {
        matrix[result[1]][result[2]] = player_var;
        return;
    }
    result[0] = 0;
    // Check if there is a strategic position for the current player.
    find_strategic_position_1(matrix, result, player_var);

    if (result[0] > 0)
    {
        matrix[result[1]][result[2]] = player_var;
        return;
    }
    result[0] = 0;
    // Check if there is a strategic position for the opponent.
    find_strategic_position_1(matrix, result, player_var_not);
    // If there are multiple strategic positions for the opponent, look for a position that invalidates all of them.
    if (result[0] > 1)
    {
        oppenent_strategic_position(matrix, result, player_var_not);
        if (result[0] == 1)
        {
            matrix[result[1]][result[2]] = player_var;
            result[0] = 0;
            return;
        }
    }
    if (result[0] == 1)
    {
        matrix[result[1]][result[2]] = player_var;
        return;
    }
    result[0] = 0;
    // If no specific conditions are met, generate a random move.
    generate_random_move(matrix, result);
    matrix[result[1]][result[2]] = player_var;
}
