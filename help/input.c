#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    //int array_of_ints[4][4];
    int i,j, **ptr;
    int x,y;
    j=0;
    y=0;
    if(argc!=2)
    {
      write(1, "error",5);
      return 0;
    }
    else
    {
      ptr = (int**) malloc(4 * sizeof(int));
      while (argv[y][x] != '\0')
      {
        while(j<4)
        { 
          ptr[i] = (int*)malloc(4 * sizeof(int));
          i=0;
          x=0;
          while (i<4)
          { 
            if( argv[y][x] == ' ') 
              x++;
            ptr[j][i] = atoi(argv[x]);  
            i++;
            x++;
          }
          j++;
          y++;
        }
      }
    }
    printf("%d ", ptr[j][i]);
    free(ptr);
    return 0;
    
}
