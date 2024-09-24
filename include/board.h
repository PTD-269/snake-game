#ifndef BOARD_H
#define BOARD_H

#include "position.h"
#include "queue.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum State {
    SPACE,
    SNAKE_BODY,
    FRUIT
};

struct Board {
    int **matrix;
    int num_of_rows;
    int num_of_cols;
    Queue *snake_body;

    void (*move)(struct Board *self, enum Direction dir);
    void (*display)(struct Board *self);
    void (*put_random_food)(struct Board *self);
    // int (*isFruit)(struct Board *self);

};

struct Board *init_board(int num_of_rows, int num_of_cols);
void move(struct Board *self, enum Direction dir);
void display(struct Board *self);
void put_random_food(struct Board *self);
// int isFruit(struct Board *self);

int** return_dynamic_array(int row, int col);
char convert_number_to_character(int num);
enum Direction convert_number_to_enum(int num);
enum Direction write_from_user_move();
int randint(int n);

#endif // BOARD_H