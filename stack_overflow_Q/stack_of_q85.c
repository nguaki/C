#include <stdio.h>
#include <stdlib.h>

enum ABC {a=1, b ,c };

void
vX( enum ABC x )
{
    printf( "%d\n", x );
}

int
main(void)
{
   enum ABC A;
   
   A = a;
   
   vX( A );

   return 0;
}