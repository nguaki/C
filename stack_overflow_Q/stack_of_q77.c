#include <stdio.h>
#include <stdlib.h>

typedef struct _xyz
{
    int x;
    int y;
}XYZ;

int
main(void)
{

   XYZ *pXYZ = malloc(sizeof(pXYZ));
   XYZ *pXYZ1 = malloc(sizeof(*pXYZ1));  //<==== This is correct way!!!
   
   printf( "sizeof pXYZ = %u\n", sizeof(pXYZ));
   printf( "sizeof *pXYZ1 = %u\n", sizeof(pXYZ1));
   
   pXYZ->x = 10;
   pXYZ->y = 15;
   
   printf( "%d  %d\n", pXYZ->x, pXYZ->y );
   
   pXYZ1->x = 20;
   pXYZ1->y = 25;
   
   printf( "%d  %d\n", pXYZ1->x, pXYZ1->y );
   
   return 0;
}
  
   