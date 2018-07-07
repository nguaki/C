#include <stdio.h>

int
main(void)
{
   int a = 10; 
   int b = (++a) + (++a) + (++a);
   
   printf( "%d\n", b );
   
   return 0;
}