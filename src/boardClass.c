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
      while ((line = my_readline(fd))){
          
      }
  }      
    
  return bd;
}