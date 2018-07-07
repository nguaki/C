// March 30, 2017
//Second best way to return a character array. 
//This method utilizes malloc() at functional level.
//
//Negative: The freeing up the memory takes place elsewhere.
//OUTPUT:
//cp = hello malloc

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *
return_malloc()
{

    char *cp;
    
    cp = malloc(20);
    
    if( cp != NULL )
        strncpy( cp, "hello malloc", 20 );
    
    return cp;
}

int
main(void)
{

    char *cp;
    
    cp = return_malloc();
    
    printf( "cp = %s\n", cp );
    
    if( cp )
        free(cp);
    return 0;
}
