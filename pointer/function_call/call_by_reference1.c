//////////////////////////////////////////////////////////////
// April 5, 17
//
// OUTPUT
// -5
//
// DESCRIPTION
//  In func(), the variables b and c get swapped.
//  So the new values are.
//  b = 6 c = 4
//
//  a - b - c = 5 - 6 - 4 = -5
//
// Apr 25, 18      Added Comments.
//////////////////////////////////////////////////////////////
#include <stdio.h>

//Swaps two values.
void 
func( int *a, int *b )
{
    int c;
    
    c  = *a;
    *a = *b;
    *b =  c;
}

int
main(void)
{
    int a, b, c;
    
    a = 5;
    b = 4;
    c = 6;
    
    func( &b, &c );
    
    printf( "%d\n", a-b-c);
    
    return 0;
}

    