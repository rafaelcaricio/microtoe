#include<stdio.h>
#include<stdlib.h>

#define PLAYER_X 1;
#define PLAYER_O 0;
#define EMPTY -1;

#define NOT_FINISHED 1
#define X_IS_THE_WINNER 2
#define O_IS_THE_WINNER 4
#define GAME_OVER 8

typedef struct Player {
    char *name;
    unsigned int total_points;
} Player;

typedef struct Game {
    int table[3][3];
    int round;
} TicTacToe;


TicTacToe* tictactoe_init() {
    TicTacToe *self;
    int i = 0;
    int j = 0;

    self = malloc(sizeof(TicTacToe));
    if ( !self ) {
        printf("Ow god, no have more memmory... O.o'");
        exit(1);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            self->table[i][j] = EMPTY;
        }
    }
    self->round = 0;

    return self;
}

int tictactoe_get_current_player(TicTacToe *self) {
    return self->round % 2;
}

int tictactoe_play(TicTacToe *self, int x, int y) {
    self->round++;
    self->table[x][y] = tictactoe_get_current_player(self);
    return 0;
}

int tictactoe_game_status(TicTacToe *self) {
    return NOT_FINISHED;
}
