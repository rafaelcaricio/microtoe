#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "tictactoe.h"

void test_game_initialization() {
    TicTacToe *game = tictactoe_init();
    int i, j, empty = EMPTY;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            assert(game->table[i][j] == empty && "The game table should be initialized with EMPTY value!");
        }
    }

    assert(game->round == 0 && "The first round should be 0");

    free(game);
}

void test_current_player() {
    TicTacToe *game = tictactoe_init();
    int player_x = PLAYER_X;
    int player_o = PLAYER_O;
    
    game->round = 1;
    assert(tictactoe_get_current_player(game) == player_x && "The current player in round 1 should be X!");

    game->round = 2;
    assert(tictactoe_get_current_player(game) == player_o && "The current player in round 2 should be O!");

    game->round = 34;
    assert(tictactoe_get_current_player(game) == player_o && "The current player in round 34 should be O!");

    game->round = 7;
    assert(tictactoe_get_current_player(game) == player_x && "The current player in round 7 should be X!");

    free(game);
}

void test_first_play() {
    TicTacToe *game = tictactoe_init();
    int player_x = PLAYER_X;

    tictactoe_play(game, 2, 2);

    assert(game->round == player_x && "The round should be 1.");
    assert(game->table[2][2] == player_x && "The first player have played.");

    free(game);
}

void test_game_status() {
    TicTacToe *game = tictactoe_init();
    int still_game_and_no_winners = NOT_FINISHED;
    
    tictactoe_play(game, 0, 0);
    assert(tictactoe_game_status(game) == still_game_and_no_winners && "Any player are winner, but not should be!");

    tictactoe_play(game, 0, 1);
    assert(tictactoe_game_status(game) == still_game_and_no_winners && "Any player are winner, but not should be!");

    tictactoe_play(game, 1, 0);
    assert(tictactoe_game_status(game) == still_game_and_no_winners && "Any player are winner, but not should be!");

    tictactoe_play(game, 1, 1);
    assert(tictactoe_game_status(game) == still_game_and_no_winners && "Any player are winner, but not should be!");

    tictactoe_play(game, 2, 0);
    assert(tictactoe_game_status(game) > still_game_and_no_winners && "The player X should be the winner!");
}

int main(int argv, char** argc) {

    test_game_initialization();
    test_current_player();
    test_first_play();
    test_game_status();

    printf("\033[D\033[D\033[1;31mTests finished!\033[0m\n");

    return 0;
}
