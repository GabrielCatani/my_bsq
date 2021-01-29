#include "../includes/my_bsq.h"

int  main(int argc, char **argv)
{
  int fd = 0;
  int big_square_size = 0;

  if (argc == 2){
    fd = open(argv[1], O_RDONLY);
    if (fd){
      Board bd;
      bd = new_board(fd);
      if (bd){
        big_square_size = find_biggest_square(bd);
        print_biggest_square(bd, big_square_size);
        delete_board(bd);
      }
      close(fd);
    }
  }
  return 0;
}