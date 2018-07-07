//March 29, 17
//
//This is the best method to return an array of characters.
//It utilizes the malloc() and sends in the pointer as an arguement.
//
//It makes the memory management more visible.
//OUTPUT
//cp = hello str_cpy

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
str_cpy( char *cp, int size)
{
    strncpy( cp, "hello str_cpy", size );
}

int
main(void)
{

    char *cp;
    
    cp = malloc(50);
    
    str_cpy(cp, 20);
    
    printf( "cp = %s\n", cp );
    
    if( cp )
        free(cp);
    return 0;
}
