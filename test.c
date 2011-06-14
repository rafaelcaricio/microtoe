#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "tictactoe.h"

void test_game_initialization() {
    TicTacToe *game = tictactoe_init();
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            assert(game->table[i][j] == -1 && "The game table should be initialized with EMPTY value!");
        }
    }

    assert(game->round == 0 && "The first round should be 0");

    free(game);
}

void test_current_player() {
    TicTacToe *game = tictactoe_init();
    
    game->round = 1;
    assert(tictactoe_get_current_player(game) == 1 && "The current player in round 1 should be X!");

    game->round = 2;
    assert(tictactoe_get_current_player(game) == 0 && "The current player in round 2 should be O!");

    game->round = 34;
    assert(tictactoe_get_current_player(game) == 0 && "The current player in round 34 should be O!");

    game->round = 7;
    assert(tictactoe_get_current_player(game) == 1 && "The current player in round 7 should be X!");

    free(game);
}

void test_first_play() {
    TicTacToe *game = tictactoe_init();

    tictactoe_play(game, 2, 2);

    assert(game->round == 1 && "The round should be 1.");
    assert(game->table[2][2] == 1 && "The first player have played.");

    free(game);
}

int main(int argv, char** argc) {

    test_game_initialization();
    test_current_player();
    test_first_play();

    printf("Tests finished!\n");

    return 0;
}
