///////////////////////////////////////////////////////////////////////////////////
// Feb 11, 2017
// 
// Assigns upper case alphabet to a character pointer using ascii numberical values.
//
// Apr 26, 18   Quite simple but has a complex significance.
//              Char is assigned integer but when it prints using %s specifier
//              the character representation of its ASCII value is printed.
//              So it goes in as decimal, but the output is character.
////////////////////////////////////////////////////////////////////////////////////

//OUTPUT
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

#include <stdio.h> 
#include <stdlib.h>


int
main(void)
{
    char *ptr, *p;
    int i;
    
    ptr = (char *)malloc((26+1)*sizeof(char));
    
    p = ptr;
    
    for( i=65; i<91; i++ )
        *p++ = i;

    //We want this to be a string.
    //Need a string null char.
    *p = '\0';
    
    puts( ptr );
    
    free( ptr );
    return 0;
}