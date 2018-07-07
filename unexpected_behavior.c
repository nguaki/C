//////////////////////////////////////////////////////////////////
//
// April 3, 2017
//
// DESCRIPTION:
// When multiple expressions and assignments are evaluated on a same line,
// the order of execution is not necessarily from left to right.
//
// The outputs differ across different OS.
//
// OUTPUT
// 0 1 0
// 5 0 1 0
//////////////////////////////////////////////////////////////////
#include <stdio.h>

int
main(void)
{

    int a = 4, b = 5;
    
    printf("%d %d %d\n", a==b, a < b, a > b );

    //If the execution takes place from left to right,
    //the expected output would be 5 1 0 0.
    //The output is 5 0 1 0.
    
    printf("%d %d %d %d\n", a=b, a==b, a < b, a > b );
    return 0;
}