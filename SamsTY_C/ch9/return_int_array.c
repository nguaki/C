//Feb 11, 17
//
//Demonstration a function that returns pointer to an int array.
//
// Apr 26,18   Added a method to print out results using *X++ method.
//
/*
OUTPUT
7
9
11
13
15
*/
#include <stdio.h>

int itotal[5];

int *
add_arrays( int *ia, int *ib )
{
    int i;
    
    for( i = 0; i < 5; i ++ )
        itotal[i] = ia[i] + ib[i];

    return itotal;
    
}

int
main(void)
{
    int ia[5] = { 1, 2, 3, 4, 5 };
    int ib[5] = { 6, 7, 8, 9, 10 };
    int *ic, i;
    
    ic = add_arrays( ia, ib );
    
    for( i = 0; i < 5; i++ )
        //printf( "%d\n", ic[i] );
        printf( "%d\n", *ic++ );  //This works also.  4-26-18
        
    return 0;
}
