#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "queue.h"
#include "position.h"

struct Board* init_board(int num_of_rows, int num_of_cols) {
    struct Board *board = malloc(sizeof(struct Board));
    // Initialize function pointers
    board->move = move;
    board->display = display;
    board->put_random_food = put_random_food;
    // board->isFruit = isFruit;
    // Initialize attributes
    board->num_of_rows = num_of_rows;
    board->num_of_cols = num_of_cols;
    board->matrix = return_dynamic_array(board->num_of_rows, board->num_of_cols);
    
    board->snake_body = createQueue();
    Position init_snake_pos = (Position){0, 0};

    board->snake_body->enqueue(board->snake_body, init_snake_pos);
    
    board->matrix[init_snake_pos.row_idx][init_snake_pos.col_idx] = 1;
    board->put_random_food(board);
    return board;
}

void move(struct Board *board, enum Direction dir) {
    //Getting new head 
    Position head_pos = board->snake_body->rear->data;
    switch (dir) {
        case UP:  
            head_pos.row_idx--;
            break;
        case DOWN:
            head_pos.row_idx++;
            break;
        case LEFT:
            head_pos.col_idx--;
            break;
        case RIGHT:
            head_pos.col_idx++;
            break;
    }
    board->snake_body->enqueue(board->snake_body, head_pos);
    int state = board->matrix[head_pos.row_idx][head_pos.col_idx];

    board->matrix[head_pos.row_idx][head_pos.col_idx] = 1;
    if (state == 2) 
    {
        board->put_random_food(board);
        
    } else if (state == 1) {
        printf("Game over!.\n");
        exit(EXIT_SUCCESS);
    } 
    else {
        //Cut tail in both matrix and snake if there is no fruit on the next move
        Position tail_pos = board->snake_body->dequeue(board->snake_body);
        board->matrix[tail_pos.row_idx][tail_pos.col_idx] = 0;
    }
    
    
}

void reflect_each_move()
{

}

void display(struct Board *board) {
    char symbol;
    for (int i = 0; i < board->num_of_rows; i++) {
        for (int j = 0; j < board->num_of_cols; j++) {
            symbol = convert_number_to_character(board->matrix[i][j]);
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

int** return_dynamic_array(int row, int col) {
    int **board = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        board[i] = malloc(col * sizeof(int));
    }
    return board;
}

char convert_number_to_character(int num) {
    switch (num) {
        case 0: return 'o';
        case 1: return 'x';
        case 2: return '*';
        default: return 'q';
    }
}

enum Direction convert_number_to_enum(int num) {
    switch (num) {
        case 0: return DOWN;
        case 1: return UP;
        case 2: return LEFT;
        case 3: return RIGHT;
        default: return DOWN; // Default case to avoid warnings
    }
}

enum Direction write_from_user_move() {
    int move_ment;
    printf("\n");
    printf("0: DOWN\n");
    printf("1: UP\n");
    printf("2: LEFT\n");
    printf("3: RIGHT\n");
    printf("Tell me your move: ");
    scanf("%d", &move_ment);
    printf("\n");
    return convert_number_to_enum(move_ment);
}

void put_random_food(struct Board *self) {
    int row = randint(self->num_of_rows) - 1;
    int col = randint(self->num_of_cols) - 1;
    while (self->matrix[row][col] != 0) 
    {
        row = randint(self->num_of_rows) - 1;
        col = randint(self->num_of_cols) - 1;
    }
    self->matrix[row][col] = 2;
}

int randint(int n) {
    return rand() % (n + 1);
}

// int isFruit(struct Board *self) {
//     // int row = self->current_pos.row_idx;
//     // int col = self->current_pos.col_idx;
//     return 1; 
// }