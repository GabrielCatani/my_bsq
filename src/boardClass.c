#include "../includes/my_bsq.h"
#include "../includes/utils.h"

Board set_board(int fd){
    char *line = NULL;
    Board bd = NULL;
    bd = (Board)malloc(sizeof(boardObj));
    
    if (!bd)
        return NULL;
    line = my_readline(fd);
    bd->nbr_lines = atoi(line);
    free(line);
    line = NULL;

    bd->board = (int **)malloc(sizeof(int *) * bd->nbr_lines);
    int index = 0;
    while (index < bd->nbr_lines){
        bd->board[index] = (int *)malloc(sizeof(int) * bd->nbr_lines);
        index++;
    }

    return bd;
}

Board fill_board(Board bd, int fd){
    char *line = NULL;
    int i = 0;
    int j = 0;

    while ((line = my_readline(fd))){
        j = 0;
        while (line[j]){
            if (line[j] == 'o')
            bd->board[i][j] = 0;
            else if (line[j] == '.')
            bd->board[i][j] = 1;
            j++;
        }
        i++;
    free(line);
    line = NULL;
    }
    return bd;
}

Board  new_board(int fd){
  Board bd;
  bd = set_board(fd);
  
  if (bd){
    bd = fill_board(bd, fd);
  }
  return bd;
}

void delete_board(Board bd){
    int index = 0;

    while (index < bd->nbr_lines){
        free(bd->board[index]);
        bd->board[index] = NULL;
        index++;
    }
    free(bd->board);
    bd->board = NULL;
    free(bd);
    bd = NULL;
}

void print_board(Board bd){
    int index = 0;
    int element_index = 0;

    while (index < bd->nbr_lines){
      element_index = 0;
      while(element_index < bd->nbr_lines){
        printf("%d", bd->board[index][element_index]);
        element_index++;
      }
      printf("\n");
      index++;
    }
}

/*
void find_biggest_square(Board bd){

}
*/