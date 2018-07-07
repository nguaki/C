#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int game_sz = 5;
#define UNDO_DEPTH 25



void boardSave(int *board[game_sz], int game_sz, int *history[UNDO_DEPTH][game_sz]) 
{
    int i,j,k;

    for( i = 0; i < UNDO_DEPTH - 1; i++)
        for( j = 0; j < game_sz; j ++ )
            for( k = 0; j < game_sz; j ++ )
                history[i+1][j][k] = history[i][j][k];

     for( i = 0; i < game_sz - 1; i++)
        for( j = 0; j < game_sz; j++ )
            history[0][i][j] = board[i][j];
}

int
main(void)
{
    int *board[game_sz];
    int *history[UNDO_DEPTH][game_sz];
    int i, j;
    

    for (i = 0; i < game_sz; ++i) 
        board[i] = calloc(game_sz, sizeof(int));
    board[0][0] = 1;
        
    // Allocate array for the history
    for ( i = 0; i < UNDO_DEPTH; ++i)
        for ( j = 0; j < game_sz; ++j)
            history[i][j] = calloc(game_sz, sizeof(int));

    
    boardSave( board, game_sz, history);

    return 0;
}