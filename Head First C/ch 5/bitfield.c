//Jan 25, 17
//
//Demonstrates memory efficiency by using bitfields in typedef struct.
//
/*
size = 4
Republican
SANDERSON
======================================
Democratic
CLINTON
*/

#include <stdio.h>

//:1 is a bitfield declaration.
typedef struct{
    unsigned int repulic:1;
    unsigned int voting_for_trump:1;
    unsigned int voting_for_clinton:1;
    unsigned int voting_for_sanderson:1;
}survey;


void
display(  survey s )
{
    if( s.repulic )
        printf( "Republican\n" );
    else
        printf( "Democratic\n" );
    if( s.voting_for_trump )
        printf( "TRUMP\n" );
    if( s.voting_for_clinton )
        printf( "CLINTON\n" );
    if( s.voting_for_sanderson )
        printf( "SANDERSON\n" );

    
}

int
main()
{
    survey s1 = { 1, 0, 0, 1 };
    survey s2 = { 0, 0, 1, 0 };
    
    printf( "size = %i\n", (int)sizeof(s1) );
    display( s1 );
    printf( "======================================\n" );
    display( s2 );

    return 0;
}