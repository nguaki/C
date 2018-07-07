/*
April 6, 17

swapptr.c

OUTPUT:
    x=7 y=5
    x=5 y=7
    *m = 7, *n = 5
    x = 7, y = 5

DESCRIPTION:
    Describes how to use single pointer and double pointer to swap values.
*/
#include <stdio.h>


void swapptr( unsigned int *m, unsigned int *n )
{
    unsigned int temp;

    temp = *m;
    *m = *n;
    *n = temp;
    
}

////////////////////////////////////////////////////////////////////////////////
// m is a pointer to pointer to unsigned int
// n is a pointer to pointer to unsigned int
//
//From main:
// [5]   [7]   [100]  [200]
//  x     y     m       n
// 100   200   300     400
//
//From function:
// [300]  [400]
//   m      n
//
//  temp = **m;
//  Since m is a double pointer to an int, it must behave like this.
//   
//  m has memory address of 300.
//  *m has to get the content of mem address of 300, which is 100.
//  Since m is a double pointer, it must behave like a double pointer.
//  **m has to get the content of mem address of 100, which is 5.
//
//  temp = 5;
//
//  **m = **n;
//  memory address of 300->100 now has the content of memory address of 400->200.
//  **m = 7;
//
//  **n = temp;
//  memory address of 400->200 now has 5.
////////////////////////////////////////////////////////////////////////////////
void swapptr1( unsigned int **m, unsigned int **n )
{
    unsigned int temp;

    temp = **m;
    **m = **n;
    **n = temp;
    
}

int
main( int argc, char **argv )
{

    unsigned int x = 5, y = 7;
    unsigned int *m = &x, *n = &y;
    
    swapptr( &x, &y ); 
    printf( "x=%d y=%d\n", x, y);
    //Swaps the pointer addresses.
    swapptr( m, n ); 
    printf( "x=%d y=%d\n", x, y);

    swapptr1( &m, &n );//Works!!!  Sending the address of the pointer.

    printf( "*m = %d, *n = %d\n", *m, *n);
    printf( "x = %d, y = %d\n", x, y);

    return 0;
}