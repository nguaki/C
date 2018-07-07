//Feb 24, 17
//ex23.c
//
// Coping one string to another string.
// Implementation of unit tests.
//
/*
Continuing.
1000 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

*/
#include "dbg.h"
#include <stdio.h>
#include <string.h>

int
zed_device( char *from, char *to, int count )
{

    int n;
        
    n = (count + 7 )/8;
        
    switch(count%8)
    {
        case 0:
xyz:        *to++ = *from++;
        case 7:
            *to++ = *from++;
        case 6:
            *to++ = *from++;
        case 5:
            *to++ = *from++;
        case 4:
            *to++ = *from++;
        case 3:
            *to++ = *from++;
        case 2:
            *to++ = *from++;
        case 1:
            *to++ = *from++;
        if (--n>0) goto xyz; //There must be a better way than using goto.
    }    
    
   return count; //wait a sec. count doesn't change. Weird!!(4-25-18)
    //return 999;
}

/////////////////////////////////////////////////////////////////////
// Description:
// Checks if testStr has all characters that are equal
// to expChar.
//
// OUTPUT:
//     0    fails
//     1    success
//
////////////////////////////////////////////////////////////////////
int
valid_copy( char *testStr, char expChar, int count )
{
    int i;
    
    for( i=0; i<count; i++){
        //if( testStr[i] != 'x' )
        if( testStr[i] != expChar )
            return 0;
    }
    
    return 1;
}

int
main( int argc, char *argv[] )
{
    char from[1000] = { 'x' };
    char to[1000]   = { 'y' };
    int  rc;
    
    printf( "original from = %s\n", from);
    printf( "original to = %s\n", to);
    
    memset( to,   'y', 1000 );
    memset( from, 'x', 1000 );
    printf( "after memset from = %s\n", from);
    printf( "after memset to = %s\n", to);
    
    rc = zed_device( from, to, 1000 );
    printf( "%d\n %s\n", rc, to );
    check( rc==1000, "zed_device failed. Returned %d\n", rc);
    
    //Setup so check() fails.
    memset( to, 'y', 5 );
    
    //If valid_copy doesn't return 1, error prints.
    check( valid_copy( to, 'x', 1000 ) == 1, "Zed device failed in copy.");
    
error:
    return 0;
}