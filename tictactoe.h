#include<stdio.h>
#include<stdlib.h>

typedef struct Player {
    char *name;
    unsigned int total_points;
} Player;

typedef struct Game {
    int table[3][3];
    int round;
} TicTacToe;

#define X 1;
#define O 0;
#define EMPTY -1;

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
