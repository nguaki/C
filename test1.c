#include <stdio.h>


int
function_a( void *a)
{
    int *p;
    
    p = (int *)a;
    
    return *p;
}

int
function_b( void *a)
{
    //int *p;
    
    //p = (int *)a;
    
    return (int)*a;
}
int
main(void)
{
    int i = 10;
    
    i = function_a( &i );
    
    printf( "%d\n", i );
    
    return 0;
}