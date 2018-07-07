////////////////////////////////////////////////////////////////////
// March 28, 2017
//
//This is a case of undefind behavior where an addition of 100
//exceeded the integer max.
//The addition caused the number to be a negative number.
//
//Integer overflow has occurred.
//a + 100  = -2147483550
// 
////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <limits.h>

int
main(void)
{
    int a = INT_MAX-1;
    
    if( a+100 < a){    
        printf( "Integer overflow has occurred.\n");
        printf( "a + 100  = %i\n", a+100);
        return 1;
    }
    
    //if( a < INT_MAX - 100 )  <== this is a fix
    printf( "a = %i\n", a);

    return 0;
}