#include <unistd.h>

int g_row = 4;
int g_column = 4;
int g_board_input[4][4]
/* {
    {0, 0 ,0, 0}, //col_up
    {0, 0 ,0, 0}, //col_down
    {0, 0 ,0, 0}, //row_left
    {0, 0 ,0, 0}  //row_right
}*/

void  ft_putchar

void print_grid()
{
  int row;
  int column;

  row =0;
  while(row < g_row) //Row loop until = Global Row
  {
      column =0;
      while(column < g_column) //Column loop until = Global Column
      {
        printf("%d ",g_board_input[row][column]); //Print g_board_grid
        // printf("%d ",g_board_grid[row][column]); //Print g_board_grid
        column++;
      }
    printf("\n");
    row++;
  }
}

int main(int ac, char *av[])
{
  if(ac==2)
  {
    print_grid();
  }
  ft_putchar('\n');
  return 0;
}