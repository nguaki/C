//  April 4, 17
//
//  x = (-3)*4%(-6)/5;    Identify that -3, -6 is a unary operator, not a minus.
//                        Unary operator has higher precedence.
//                        Put a parenthesis around unary operation.
//  x = (((-3)*4)%(-6))/5 
//                        %, /, * opertors have equal precedence so the operations
//                        take place from left to right.
//  x = (-12 % -6 )/5     -12 mod -6 equals 0.
//  x = 0/5
//  x = 0
#include <stdio.h>

int
main(void)
{
    int x = 0;
    
    x = -3*4%-6/5;
    
    printf( "%d\n", x );

    return 0;
}