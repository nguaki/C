// Feb 11. 2017
//
// demonstration of *p++
//
/*
   1    1.0000
   2    2.0000
   3    3.0000
   4    4.0000
   5    5.0000
   6    6.0000
   7    7.0000
   8    8.0000
   9    9.0000
   0    0.0000
*/
#include <stdio.h>
#include <stdlib.h>

int   ia[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
float fa[10] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };

int
main( void )
{
    int   *pi, i;
    float *pf;
    
    pi = ia;  //same as pi = &ia[0];
    pf = fa;  //same as pf = &fa[0];
    
    for( i = 0; i < 10; i++ )
        //Compound operation.
        //Dereferencing has the priority and then pointer arithmentic.
        printf( "%4d\t%4.4f\n", *pi++, *pf++ );


    return 0;
}