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

int ft_errorcatch(int argc, char *args[], int *retArray, int _i)
{
  int result;
  int i;
  
  if (argc != 2)
  {
    result = 1;
  }
  else
  {
    convertintoarray(args[1], retArray);
    i = 0;
    while (i < _i)
    {
      if ((retArray[i] > 0) && (retArray[i] < 5))
      {
        result = 0;
      }
      else
      {
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
  int retArray[100];

  error = ft_errorcatch(argc, args, retArray, 16);
  if (error == 0)
  {
    //the rest of the group's code goes here
    //you can use retArray for the rest of the other codes
  }
  else
  {
    ft_printf("ERROR\n");
  }
}
