#include "../includes/my_bsq.h"
#include "../includes/utils.h"

Board  new_board(int fd){
  Board bd;
  char *line = NULL;
  bd = (Board)malloc(sizeof(boardObj));
  
  if (bd){
      line = my_readline(fd);
      bd->nbr_lines = atoi(line);
      free(line);
      line = NULL;

      bd->board = (int **)malloc(sizeof(int *) * bd->nbr_lines);
      int i = 0;
      while (i < bd->nbr_lines){
          bd->board[i] = (int *)malloc(sizeof(int) * bd->nbr_lines);
          i++;
      }
      
      i = 0;
      int j = 0;
      line = my_readline(fd);
      while (j < 10){
          if (line[j] == '\n' || line[j] == 'o')
            bd->board[i][j] = 0;
        else
            bd->board[i][j] = 1;
          j++;
      }

    
      i = 0;
      while (i < 10){
          j = 0;
          while(j < 10){
              printf("%d", bd->board[i][j]);
              j++;
          }
          printf("\n");
          i++;
      }
  }     

  return bd;
}