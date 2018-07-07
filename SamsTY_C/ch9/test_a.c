// Feb 11, 17
// Demonstrating that the integer array is sent 
// via reference.
// When array is sent, a copy is not sent.  But rather
// the address is sent.
//
// OUTPUT
// 10
#include <stdio.h>

void
xyz( int *xx )
{ 
    xx[0] = 10;
}

int
main(void)
{
    int ia[5] = { 1, 2, 3, 4, 5 };
    
    xyz(ia);
    
    printf( "%d\n", ia[0] );
    
    return 0;
}