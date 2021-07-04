// gcc -Wextra -Wall -Werror testv2.c -o main
// ./main "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// ./main '1 2 3 4'
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int g_grid_length = 4;
int g_board_input[4][4] = {
    {0, 0 ,0, 0}, //col_up
    {0, 0 ,0, 0}, //col_down
    {0, 0 ,0, 0}, //row_left
    {0, 0 ,0, 0}  //row_right
};
int g_board_grid[4][4] = {
    {0, 0 ,0, 0},
    {0, 0 ,0, 0},
    {0, 0 ,0, 0},
    {0, 0 ,0, 0}
};

void	ft_putchar(char c)
{
  write(1, &c, 1);
}

void storing_input(char *av[])
{
  int i;
  int row;
  int column;

  row =0;
  column =0;
  i =0;
  while (av[1][i] !='\0') //loop each character until finish
  {
    if (av[1][i] > 47 && av[1][i] < 53) //store only if it is between 1 to 4
    {
      if (column == g_grid_length) // if column = g_column, reset column and row ++
      {
        column =0;
        row++;
      }
      g_board_input[row][column] = av[1][i] - 48;
      // printf("input[%d][%d] = %d \n",row, column, g_board_input[row][column]); //Print saved user input
      column++;
    }
    i++;
  }
}

void insert_top_down(int column)
{
  int i;

  i =0;
  while(i< g_grid_length)
  {
    g_board_grid[i][column] = i + 1;
    i++;
  }
}

void insert_down_top(int column)
{
  int i;
  int num;

  i =0;
  num =4;
  while(i< g_grid_length)
  {
    g_board_grid[i][column] = num--;
    i++;
  }
}

void insert_left_right(int row)
{
  int i;

  i =0;
  while(i< g_grid_length)
  {
    g_board_grid[row][i] = i + 1;
    i++;
  }
}

void insert_right_left(int row)
{
  int i;
  int num;

  i =0;
  num =4;
  while(i< g_grid_length)
  {
    g_board_grid[row][i] = num--;
    i++;
  }
}

void found4(int row, int column)
{
  if(row == 0) //Found in Column_Up
  {
    insert_top_down(column);
  }
  else if(row == 1) //Found in Column_Down
  {
    insert_down_top(column);
  }
  else if(row == 2) //Found in Row_Left
  {
    insert_left_right(column);
  }
  else if(row == 3) //Found in Row_Right
  {
    insert_right_left(column);
  }
}

void fill()
{
  int row;
  int column;

  row =0;
  while(row < g_grid_length) //Row loop until = Global Row
  {
    column =0;
    while(column < g_grid_length) //Column loop until = Global Column
    {
      if (g_board_input[row][column] == 4) //If found 4
      {
        found4(row, column);
      }
      column++;
    }
    row++;
  }
}

void print_grid()
{
  int row;
  int column;

  row =0;
  while(row < g_grid_length) //Row loop until = Global Row
  {
      column =0;
      while(column < g_grid_length) //Column loop until = Global Column
      {
        ft_putchar('0' + g_board_grid[row][column]); // g_board_grid || g_board_input
        ft_putchar(' ');
        column++;
      }
    ft_putchar('\n');
    row++;
  }
}

int main(int ac, char *av[])
{
  if(ac==2)
  {
    storing_input(av);
    fill();
    print_grid();
  }
  ft_putchar('\n');
  return 0;
}