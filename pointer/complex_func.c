// 
// April 6, 2017
//
// OUTPUT:
//  19
//
// EXPLANATION:
//   **zz += 1 changes the value to 6.
//   local variable z is assigned to 6.
//   *yy +=2 changes the value from 6 to 8.
//   local variable y is assigned to 8.
//   return 5 + 6  + 8 returns value 19.
#include <stdio.h>

int
fca( int x, int *yy, int **zz )
{
    int y, z;
    
    **zz += 1; z = **zz;
    
    *yy += 2; y = *yy;
    
    return x + y + z;
}

int
main(void)
{

    int x, *y, **z;
    
    x = 5;
    y = &x;
    z = &y;
    
    printf(" %d\n", fca(x, y ,z ) );
    
    return 0;
}