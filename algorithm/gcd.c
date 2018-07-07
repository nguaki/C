//////////////////////////////////////////////////
//April 3, 17
//
// Algorithm for GCD.
//
//////////////////////////////////////////////////
#include <stdio.h>

int
main(void)
{
    int m, n, x, y;
    
    scanf("%d %d", &x, &y );
    
    m = x;
    n = y;
    
    while( m != n )
    {
        if (m>n)
            m = m - n;
        else
            n = n -m;
    }
    
    printf( "GCD = %d\n", n );

    return 0;
}
