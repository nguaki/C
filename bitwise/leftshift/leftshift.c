///////////////////////////////////////////////////////////////////
//
// April 3, 2016
//
// OUTPUT:
// size of short = 2
// x = 0 
// y = 4 
//
// DESCRIPTION:
// Left shift once is not always same as multiplying by 2.
// When the most significant bit is 1, left shift once does not 
// becomes same as multiplying by 2.
//
//////////////////////////////////////////////////////////////////////
#include <stdio.h>

int
main(void)
{
    unsigned short x, y;
    
    printf( "size of short = %d\n", (int)sizeof(unsigned short));
    
    x = 32768;  // 2 pow 15 = 32768
                // In binary, it looks like 10000000 00000000
                // If left shift once, it will look like 00000000 00000000.
                
    
    x = x << 1;   
    printf( "x = %d \n", x );


    y = 2;  
    
    y = y << 1;  //Left shift once is same as multiplying by 2.
    
    printf( "y = %d \n", y );
    
    return 0;
}