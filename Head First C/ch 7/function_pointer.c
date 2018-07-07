// Jan 28, 17
//
// Implementation of function pointer.
//
/*
4
9
16
*/
#include <stdio.h>
#include <stdlib.h>

int
squareIt( int x )
{
    return x * x;
}

int (* XYZ )(int);  //Declares the XYZ is a function pointer that returns an int and has
                    //an int as a parameter.


int
main()
{
    XYZ = squareIt;  // Now XYZ points to squareIt function.
    printf( "%d\n", XYZ(2));
    printf( "%d\n", XYZ(3));
    printf( "%d\n", XYZ(4));
   
    return 0;
}