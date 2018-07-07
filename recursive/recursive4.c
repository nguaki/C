/////////////////////////////////////////////////////////////
// April 6, 2017
//
//OUTPUT:
// 9
/////////////////////////////////////////////////////////////
#include <stdio.h>

int
f( int n, int k )
{
    if( n == 0 ) return 0;
    else if( n % 2 ) return f(n/2, k*2) + k;
    else return f(n/2, k*2) - k;
}

int
main(void)
{
    printf("%d\n", f(20,1) );
    return 0;
}