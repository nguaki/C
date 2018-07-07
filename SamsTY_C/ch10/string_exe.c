// Feb 11, 17
//
//Demonstration of iniatilization of literal string at the declaration of strings.
//ac = Point
//pc = Point
//string length = 5
//string length = 5
//ac = abcdef length = 6   <==NULL character doesn't count.
//ac = abcdef length = 6
//ad = abcde
// Note that a null character is added in order to make it into a string.
// However, null character is not counted in strlen() command.
//
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char ac[] = "Point";
    char *pc = "Point";  //Only at the declaration of pointer, the assignment
                                     //is possible without malloc.  The literal string
                                     //is not stored in heap, but in the constant side of the memory.
    char *p1c;
    char ad[5];
    
    // *p1c = "hhhhh\0";  <== illegal.  Must allocat memory space first
    printf( "ac = %s\n", ac );
    printf( "pc = %s\n", pc );
    printf( "string length = %u\n", (unsigned int)strlen(ac) );
    printf( "string length = %u\n", (unsigned int)strlen(pc) );
    
    strcpy( ac, "abcdef\0" );
    printf( "ac = %s length = %u\n", ac, (unsigned int)strlen(ac) );
    strcpy( ac, "abcdef" );
    printf( "ac = %s length = %u\n", ac, (unsigned int)strlen(ac) );
    
    strcpy( ad, "abcde\0");
    printf( "ad = %s\n", ad );

    return 0;
}