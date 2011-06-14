#include<stdio.h>

#include "tictactoe.h"

int main(int argv, char ** argc) {

    TicTacToe *game = tictactoe_init();

    tictactoe_play(game, 0, 0);
    tictactoe_play(game, 1, 1);
    tictactoe_play(game, 0, 1);
    tictactoe_play(game, 1, 3);
    tictactoe_play(game, 0, 2);

    free(game);

    return 0;
}
