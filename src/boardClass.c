#include "../includes/my_bsq.h"
#define READ_SIZE 10

/*
    TO-DO: create has_new_line function;
    TO-DO: create my_strjoin funciton;
    TO-DO: create my_atoi function;
    TO-DO: test print number of lines from file
*/ 
Board  *new_board(int fd){
  Board *bd = NULL;
  int rd = 0;
  char buf[READ_SIZE];
  //char *line = NULL;
  //char *tmp = NULL;
  //int index = 0;

  bd = (Board *)malloc(sizeof(Board));
  if (bd){
    while ((rd = read(fd, buf, READ_SIZE))){
      buf[rd] = '\0';
      //tmp = my_strjoin(line, buf);
      //free(line);
      //line = tmp;
      //free(tmp);
      //if (has_new_line(buf))
        //break;
    }
  }
    
  return bd;
}