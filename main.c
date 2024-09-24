#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "position.h"
#include "board.h"

int main()
{
  printf("Let start:\n");
  enum Direction dir_to_move;
  int num_of_rows;
  int num_of_cols;
  printf("Give me program size (max: 8x16)\n");
  printf("Number of rows: ");
  scanf("%d", &num_of_rows);
  printf("Number of cols: ");
  scanf("%d", &num_of_cols);
  
  struct Board *board = init_board(num_of_rows, num_of_cols);

  while (1 < 2)
  {
    printf("-----\n");
    board->display(board);
    dir_to_move = write_from_user_move();
    board->move(board, dir_to_move);
  }
}

