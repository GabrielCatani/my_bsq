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
void find_biggest_square(Board *board);
void print_board(Board board);
#endif