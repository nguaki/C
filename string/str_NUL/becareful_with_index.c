// April 5, 17
//
// EXPLANATION:
//  In C, index is everything.
//  Knowing precisely if a standard function returns n or n+1 is very important.
//  And also the understanding of the fact that hidden NULL character '\0'
//  is automatically appended to a string initialization.
//
/*
string length is 6
character at position 0 is      <=== 0th character gets a string NUL character.
character at position 1 is g
character at position 2 is n
character at position 3 is i
character at position 4 is r
character at position 5 is t
character at position 6 is s

 sa =   <=== Since 0th character is a NULL character, this  will display nothing.

Apr 25, 18   Added comments on strlen.
*/
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char *s =  "string";
    char sa[7];
    int i;
    int iLen;
    
    iLen = strlen(s);
    
    //strlen does not count string NUL character.
    printf( "string length is %d\n", iLen );
    
    //Store characters in reverse.
    for( i=0; i<=iLen; i++)
        sa[i] = s[iLen-i];
    for( i=0; i<=iLen; i++)
        printf( "character at position %d is %c\n", i, sa[i] );

        
    printf( "\n sa = %s\n", sa );
        
    return 0;
}