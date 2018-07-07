//it is not zero.
//it is one.

#include <stdio.h>

int
main(void)
{
    int a;
    
    if( a = 0 )  //This assignment returns 0.
        printf("it is zero.\n");
    else
        printf("it is not zero.\n");
        
    if( a = 1 )  //This assignment returns 1.
        printf("it is one.\n");
    else
        printf("it is not one.\n");
    
    
    return 0;
}