//May 1, 2018 - Counts how many ones in a number.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int
iCntOnes( long l )
{
    int i, iCnt = 0;
    
    for( i = 0; i < (sizeof(l) * 8); i++ ){
        if( l & 1 ) iCnt++;
        l = l >> 1;
    }
    return iCnt;
}

int
main( int argc, char **argv )
{
    long l;
    int  i, iCnt = 0;
    
    //printf("enter a long int number:");
    //scanf( "%ld", &l );
    //printf("There are %d ones.\n", iCnt);
    
    assert( 1 == iCntOnes(16) );
    assert( 1 == iCntOnes(8) );
    assert( 1 == iCntOnes(4) );
    assert( 1 == iCntOnes(2) );
    assert( 1 == iCntOnes(1) );
    assert( 4 == iCntOnes(15) );
    
    
    return 0;
}    