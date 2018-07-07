// addNums.c
//
// This program is used as an input from pipe.
//
#include <stdio.h>


int
main()
{
    int i1, i2;
    
    while( scanf( "%i %i", &i1, &i2 ) == 2 ){
        printf( "%i\n", i1 + i2 );
    }
    return 0;
}