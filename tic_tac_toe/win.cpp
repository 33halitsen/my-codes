#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void check_row(int matrix[3][3], int *counter_1, int player_var)
{
    int counter_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == player_var)
            {
                counter_2++;
            }
        }
        if (counter_2 == 3)
        {
            if (player_var == 1)
            {
                (*counter_1) = 1;
            }
            else
            {
                (*counter_1) = 2;
            }
        }
        counter_2 = 0;
    }
}

void check_column(int matrix[3][3], int *counter_1, int player_var)
{
    int counter_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[j][i] == player_var)
            {
                counter_2++;
            }
        }
        if (counter_2 == 3)
        {
            if (player_var == 1)
            {
                (*counter_1) = 1;
            }
            else
            {
                (*counter_1) = 2;
            }
        }
        counter_2 = 0;
    }
}

// The 'check_diagonal_1' function checks the diagonal at indices (0, 0), (1, 1), (2, 2).
void check_diagonal_1(int matrix[3][3], int *counter_1, int player_var)
{
    int counter_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][i] == player_var)
        {
            counter_2++;
        }
    }
    if (counter_2 == 3)
    {
        if (player_var == 1)
        {
            (*counter_1) = 1;
        }
        else
        {
            (*counter_1) = 2;
        }
    }
}

/* The 'check_diagonal_2' function checks the diagonal at indices (0, 2), (1, 1), (2, 0).
   It has a similar logic to the 'check_diagonal_1' function. */
void check_diagonal_2(int matrix[3][3], int *counter_1, int player_var)
{
    int counter_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][2 - i] == player_var)
        {
            counter_2++;
        }
    }
    if (counter_2 == 3)
    {
        if (player_var == 1)
        {
            (*counter_1) = 1;
        }
        else
        {
            (*counter_1) = 2;
        }
    }
}

void check_winner(int matrix[3][3], int *counter_1, int player_var)
{
    check_row(matrix, counter_1, player_var);
    check_column(matrix, counter_1, player_var);
    check_diagonal_1(matrix, counter_1, player_var);
    check_diagonal_2(matrix, counter_1, player_var);
}
