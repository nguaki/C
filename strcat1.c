//Segmentation fault
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    char *error = "ERROR: ";
    char *errorMessage = "Not enough memory";
    
    //char *buffer = malloc( strlen(error) + strlen(errorMessage) + 1 );
    
    //strcpy( buffer, error );
    strcat( error, errorMessage ); <===seg fault.  
    
    printf( "%s\n", error );
    printf( "%s\n", errorMessage );
    //printf( "%s\n", buffer );
    
    
    return 0;
}