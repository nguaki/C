/**
OUTPUT
##################################################
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
#                                               #
##################################################
**/
#include <stdio.h>

void
main()
{

    char c = 35; //ASCII representation of # character.
    int  i;
    
    for( i=0; i<50; i++ )
        printf( "%c", c );
    puts("");
    
    for( i=0; i<20; i++ )
        printf( "%c\t\t\t\t\t\t%c\n", c, c);

    for( i=0; i<50; i++ )
        printf( "%c", c );
    puts("");

}