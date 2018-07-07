// Illustration of dangling pointer.
//
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *i;
    
    i = malloc(sizeof i );
    
    *i = 999;
    
    printf( "%d\n", *i );
    
    free( i );
    
    i = NULL;   //Removes dangling pointer behavior.
    printf( "%d\n", *i );  //<=== Undefined behavior.
   

    return 0;
}