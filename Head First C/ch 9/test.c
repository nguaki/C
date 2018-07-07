#include <stdio.h>
#include <string.h>

int
main()
{
    char xyz[3][10];
    
    
    strcpy( xyz[0], "Hello" );
    strcpy( xyz[1], "World" );
    xyz[2][0] = '\0';
    
    printf( "%s\n", xyz[0] );
    printf( "%s\n", xyz[1] );
    printf( "%s\n", xyz[2] );
    
    char *abc[2] = { "Hello", "World" };
    
    printf( "%s\n", abc[0] );
    printf( "%s\n", abc[1] );
    //The following causes run-time seg error.
    strcpy( abc[0], "Bye" );
    strcpy( abc[1], "World" );
    printf( "%s\n", abc[0] );
    printf( "%s\n", abc[1] );

    //Following causes warning.
    //char **def = { "Hello", "World" };
    //printf( "%s\n", def[0] );
    //printf( "%s\n", def[1] );
    
    return 0;
}