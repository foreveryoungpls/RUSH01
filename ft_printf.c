#include <unistd.h>

void  ft_printf(char *str)
{
  int i;

  i = -1;
  while(i++, str[i])
  {
    write(1, &str[i], 1);
  }
}