#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define UNDO_DEPTH 25


void boardSave(int ***board, int game_sz, int ****history) {
    // Shift history to the right
    memmove(*history + 1, *history, (UNDO_DEPTH - 1) * sizeof(**history));
    // Copy board into history
    for (int row = 0; row < game_sz; ++row) {
        memcpy((*history)[0][row], (*board)[row], game_sz * sizeof((**board)[row]));
    }
}

int main(){
    // Game
    int game_sz = 5;
    
    // Allocate array for the board
    // Set each to zero.
    // Since this is a double pointer, you can think this as 2 dimension array.
    // int board[5][]
    // This is same as   int *board[5];
    int **board = calloc(game_sz, sizeof(int *));
    
    for (int i = 0; i < game_sz; ++i) board[i] = calloc(game_sz, sizeof(int));
    
    // Allocate array for the history
    int ***history = calloc(UNDO_DEPTH, sizeof(int **));
    for (int i = 0; i < UNDO_DEPTH; ++i) {
        history[i] = calloc(game_sz, sizeof(int *));
        for (int j = 0; j < game_sz; ++j) {
            history[i][j] = calloc(game_sz, sizeof(int));
        }
    }
    board[0][0] = 1;
    boardSave(&board, game_sz, &history);
}