#include "../includes/my_bsq.h"
#include "../includes/utils.h"

/*
    TO-DO: create has_new_line function;
    TO-DO: create my_strjoin funciton;
    TO-DO: create my_atoi function;
    TO-DO: test print number of lines from file
*/ 
Board  *new_board(int fd){
  Board *bd = NULL;

  bd = (Board *)malloc(sizeof(Board));
  char *line = NULL;
  if (bd){
      line = my_readline(fd);
      printf("nbr lines: %d\n", atoi(line));
      free(line);
  }      
    
  return bd;
}