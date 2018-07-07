/*
April 3, 2017

FILENAME: printArray.c

DESCRIPTION:
    Demonstrates that 2 dimensional array is stored in a contiguous memory.
    Demonstrates how pointer moves.

OUTPUT:
11
12
13
21
22
23
31
32
33
*/
#include <stdio.h>

int
main( int argc, char **argv )
{
    int intArray[4][3] = { 
                            { 11, 12, 13 },
                            { 21, 22, 23 },
                            { 31, 32, 33 },
                            {-1, -1, -1 }    //Terminating array.
                         };
                      
    int *i;
    
    //i = &intArray[0][0];   <== This works!!
    i = intArray;  // <== Works but gets a warning message. 
    
    //while( *i != NULL )
    while( *i != -1 )
    {
        printf( "%d\n", *i );
        i++;  //Increments pointer.
    }


    return 0;
}