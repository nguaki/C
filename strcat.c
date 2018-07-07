/*
Demonstration of allocating enough memory for strcat.
ERROR: 
Not enough memory
ERROR: Not enough memory
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    char *error = "ERROR: ";
    char *errorMessage = "Not enough memory";
    
    char *buffer = malloc( strlen(error) + strlen(errorMessage) + 1 );
    char *cp;
    
    strcpy( buffer, error );
    cp = strcat( buffer, errorMessage );
    
    printf( "%s\n", error );
    printf( "%s\n", errorMessage );
    printf( "%s\n", buffer );
    printf( "%s\n", cp );
    
    
    return 0;
}
