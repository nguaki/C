//10
//
#include <stdio.h>

void 
dispNumber( int n )
{
    printf( "%d\n", n );
}

int
main()
{
    void (*foo)( int n);
    
    foo = dispNumber;
    
    (*foo)(10);
    
    return 0;
}