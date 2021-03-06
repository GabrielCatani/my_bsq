#ifndef __MY_BSQ_H__
#define __MY_BSQ_H__
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
typedef struct boardObj {
  int nbr_lines;
  int **board;
}boardObj;
typedef struct boardObj* Board;
Board new_board(int fd);
int find_biggest_square(Board board);
void print_biggest_square(Board board, int big_square_size);
void print_board(Board board);
void delete_board(Board bd);
Board fill_board(Board bd, int fd);
Board set_board(int fd);
#endif