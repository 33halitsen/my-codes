#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

/* This function checks if there is a winning situation in a single move.

Example:

 x _ x  If it's the turn of (x) and (x) selects the index (0, 1), they will win.
 _ o _
 _ _ o

 */
void find_critical_position(int matrix[3][3], int result[3], int player_var)
{
    int clone[3][3];
    int counter_1 = 0;

    copy_matrix(matrix, clone);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (clone[i][j] == 0)
            {
                clone[i][j] = player_var;
                check_winner(clone, &counter_1, player_var);
                if (counter_1 > 0)
                {
                    result[0]++;
                    result[1] = i;
                    result[2] = j;
                }
                counter_1 = 0;
                clone[i][j] = 0;
            }
        }
    }
}

/* The purpose of the find_strategic_position_1 function is to find a position for player_var parameter equal to 1,
such that marking that empty space creates two critical positions.

Example:

 _ _ x  If the bot marks the index (0, 0), the next situation will be as follows:
 _ o _
 x _ o

 x _ x  If it's the player's turn and the player wants to prevent the bot from winning, they must control both the 0th row
 _ o _  and the 0th column, but this is not possible, so the bot will win.
 x _ o

If the player_var parameter is equal to 2, then the player has an advantage with such a strategic position.
*/
void find_strategic_position_1(int matrix[3][3], int result_1[3], int player_var)
{
    int clone[3][3], result[3] = {0, 0, 0};
    copy_matrix(matrix, clone);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (clone[i][j] == 0)
            {
                clone[i][j] = player_var;
                find_critical_position(clone, result, player_var);
                if (result[0] > 1)
                {
                    result_1[0]++;
                    result_1[1] = i;
                    result_1[2] = j;
                }
                result[0] = 0;
                clone[i][j] = 0;
            }
        }
    }
}

/* This function aims to find a move that can prevent all multiple strategic positions for the opponent at the same time. */
void oppenent_strategic_position(int matrix[3][3], int result[3], int player_var)
{
    int clone[3][3], result_1[3] = {0, 0, 0};

    result[0] = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            copy_matrix(matrix, clone);
            if (clone[i][j] == 0)
            {
                clone[i][j] = player_var;
                find_strategic_position_1(clone, result_1, player_var);
                if (result_1[0] == 0)
                {
                    result[0] = 1;
                    result[1] = i;
                    result[2] = j;
                    return;
                }
                result_1[0] = 0;
                clone[i][j] = 0;
            }
        }
    }
}
