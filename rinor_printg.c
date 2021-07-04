#include <unistd.h>

void  rinor_printg(int *array)
{
  int i;
  int j;
  char c;

  i = -1;
  j = 0;
  while(i++, i < 16)
  {
    c = array[i] +'0';
    write(1, &c, 1);
    if (j != 3)
    {
      write(1, &" ", 1);
      j++;
    }
    else 
    {
      write(1, &"\n", 1);
      j = 0;
    }
  }
  write(1, &"\n", 1);
}

int main(void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
  rinor_printg(array);
}