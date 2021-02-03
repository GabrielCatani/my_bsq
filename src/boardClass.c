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
        if (bd->board[index][element_index] == 120)
            printf("x");
        else if (bd->board[index][element_index] == 0)
            printf("o");
        else
            printf(".");
        element_index++;
      }
      printf("\n");
      index++;
    }
}

int add_one_bitwise(int nbr, int one){


    while (one != 0){
        int carry = nbr & one;
        nbr = nbr ^ one;
        one = carry << 1;
    }

    return nbr;
}


int find_biggest_square(Board bd){
    int i = 1;
    int j = 1;
    int min = 0;
    int max = 0;
    while (i < bd->nbr_lines){
        j = 1;
        while (j < bd->nbr_lines){
            min = bd->board[i - 1][j];
            if (bd->board[i - 1][j] < min)
                min = bd->board[i - 1][j];
            else if (bd->board[i][j - 1] < min)
                min = bd->board[i][j - 1];
            else if (bd->board[i -1][j -1] < min)
                min = bd->board[i -1][j -1];
            if (bd->board[i][j] != 0)
                bd->board[i][j] = add_one_bitwise(min, 1);
            if (bd->board[i][j] > max)
                max = bd->board[i][j];
            j++;
        }
        i++;
    }
    return max;
}

void print_biggest_square(Board board, int big_square_size){
    int i = 1;
    int j = 1;
    int found = 0;
    while (i < board->nbr_lines){
        if (found)
          break;
        j = 1;
        while (j < board->nbr_lines){
            if (board->board[i][j] == big_square_size){
                found = 1;
                break;
            }
            j++;
        }
        i++;
    }

    int counter = big_square_size;
    int index = 0;
    j++;
    i--;
    int column = j;
    while (index < big_square_size){
        counter = big_square_size;
        j = column;
        while (counter > 0){
            board->board[i][j] = 'x';
            counter--;
            j--;
        }
        i--;
        index++;
    }

    print_board(board);
}
