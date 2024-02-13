#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// initializeMatrix functions intitialize the all game matrix to begin
void initializeMatrix(int *matrix, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            *(matrix + i * size2 + j) = 0;
        }
    }
}

void print_game_board(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 1)
            {
                printf("X ");
            }
            if (matrix[i][j] == 2)
            {
                printf("O ");
            }
            if (matrix[i][j] == 0)
            {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void copy_matrix(int source[3][3], int destination[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            destination[i][j] = source[i][j];
        }
    }
}

void generate_random_move(int matrix[3][3], int result[3])
{
    int control = 0;

    srand(time(NULL));
    while (control != 1)
    {
        int i = rand() % 3;
        int j = rand() % 3;
        if (matrix[i][j] == 0)
        {
            result[0] = 1;
            result[1] = i;
            result[2] = j;
            control = 1;
        }
    }
}

// check function checks is the game matrix full or not.
int check(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void player(int matrix[3][3], int player_var)
{
    int c, r;
    printf("\nrow and colum: ");
    scanf("%d %d", &r, &c);
    if (matrix[r][c] == 2 || matrix[r][c] == 1)
    {
        printf("\nthis place are already used. select another place.\n");
        player(matrix, player_var);
    }
    else
    {
        matrix[r][c] = player_var;
    }
}