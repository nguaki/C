#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int i, total;
    
    for( i = 1; i <= 16; i ++ )
        total = total + i*i;
        
    printf( "%d\n", total );
    
    return 0;
}
        