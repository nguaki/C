#include <stdio.h>
#include <stdlib.h>

int
main(void)
{

    int i, j=1;
    
    while(j==1)
      j = scanf( "%d", &i );  //j will return 1 if input was correct
                              //j will return 0 if input was incorrect such as entering letter a.
    return 0;
}