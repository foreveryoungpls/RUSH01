#include <unistd.h>
#include <stdio.h>

void  ft_printf(char *str)
{
  int i;

  i = -1;
  while(i++, str[i])
  {
    write(1, &str[i], 1);
  }
}

void convertintoarray(char *args, int *retArray)
{
  int i;
  
  i = 0;
  while (args[i])
  {
    retArray[i/2] = (args[i] - '0');
    i = i + 2;
  }
}

int ft_errorcatch(int argc, char *args[])
{
  ft_printf("Executing function\n");
  int retArray[16];
  int result;
  int i;
  
  if (argc != 2)
  {
    ft_printf("ERROR: More than one argument\n");
    result = 1;
  }
  else
  {
    ft_printf("Only one argument\n");
    convertintoarray(args[1], retArray);
    i = 0;
    while (i < 4)
    {
      if ((retArray[i] > 0) && (retArray[i] < 5))
      {
        printf("retArray[%d]: %d is within 0 to 5\n", i, retArray[i]);
        result = 0;
      }
      else
      {
        //printf("retArray[%d]: %d\n has wrong value", i, retArray[i]);
      result = 1;
      }
      i++;
    }
  }
  return (result);
}

int main(int argc, char *args[])
{
  int error;

  error = ft_errorcatch(argc, args);
  if (error == 0)
  {
    ft_printf("Values valid\n");
    //the rest of the group's code goes here
  }
  else
  {
    ft_printf("ERROR\n");
  }
}
