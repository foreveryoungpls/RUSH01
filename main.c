#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int *input(char *av[], int *con_array)
{
  int i;

  i =0;
  while(av[1][i] !='\0') //loop until finish
  {
    if( av[1][i] == ' ') //if array is space then i++ to skip
    {
      i++;
    }
    con_array[i] = av[1][i];
    i++;
  }
  return (con_array);
}

int main(int ac, char *av[])
{ 
  int row;
  int column;
  int i;
  int arr[4][4];
  int con_array[16];

  row =0;
  column =0;
  if(ac==2)
  {
    input(av, con_array);
    chk_conditions(av[1]);
  }
  ft_putchar('\n');
  return 0;
}