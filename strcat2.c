#include <stdio.h>
//Demonstration of how strcat can modify the address of second arguement.
//ERROR: Not enough memory
//h memory    <=== The second arguement got all modfified
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    char error[] = "ERROR: ";  //allocates 8 bytes (7+1)
    char errorMessage[] = "Not enough memory";
     
    printf( "%s\n", error );
    printf( "%s\n", errorMessage );
   
    //error = strcat( error, errorMessage );  <==Causes compilation error
    strcat( error, errorMessage ); 
    
    printf( "%s\n", error );    //NUL char is replaced with "Not enought memory"
    printf( "%s\n", errorMessage ); //The first byte of this variable is pointing at letter 'h'

    return 0;
}
