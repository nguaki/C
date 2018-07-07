// Feb 22, 2016
//
// Demonstration of UNION.
//
// UNION is OR stucture. This means that only one structure element is assigned.
/*
OUTPUT
size of structure = 8
char  = X    <==== Only this is valid.
short = 28760
int   = -594907048
float = -311736560364027904.000000
double = 0.000000
=======================================
char  = d
short = 100
int   = 100  <===Only this is valid.
float = 0.000000
double = 0.000000

April 26, 18   Wrote comments on UNION.
*/

#include <stdio.h>

union test{
    char   c;
    short  s;
    int    i;
    float  f;
    double d;
};

int
main(void)
{

    union test ut;
    
    printf( "size of structure = %d\n", (int)sizeof(union test));
    
    ut.c = 'X';
    
    printf( "char  = %c\n", ut.c );
    printf( "short = %d\n", ut.s );
    printf( "int   = %d\n", ut.i );
    printf( "float = %f\n", ut.f );
    printf( "double = %f\n", ut.d );

    printf( "=======================================\n" );
    
    ut.i = 100;
    
    printf( "char  = %c\n", ut.c );
    printf( "short = %d\n", ut.s );
    printf( "int   = %d\n", ut.i );
    printf( "float = %f\n", ut.f );
    printf( "double = %f\n", ut.d );

    return 0;
}