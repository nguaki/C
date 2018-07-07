// 1 - add
// 2 - subtract
// 3 - divide
// 4 - multiplication

#include <stdio.h>

int iResult;

void *
add( void *i, void *j )
{
    int *x = (int *)i;
    int *y = (int *)j;
    
    printf( "x = %d  y = %d\n", *x, *y);
    iResult = *x + *y;
    printf( "iResult = %d\n", iResult);
    
    return &iResult;
}
void *
sub( void *i, void *j )
{
    int *x = (int *)i;
    int *y = (int *)j;
    
    printf( "x = %d  y = %d\n", *x, *y);
    iResult = *x - *y;
    printf( "iResult = %d\n", iResult);
    
    return &iResult;
}

int
main(int argc, char **argv)
{
    void *(*op)( void *, void * );
    int *iRes;
    int x;
    int y;
    
    x = 3; y = 5;
    iRes = (int * )add( &x, &y );
    printf( "iRes = %d\n", *iRes );
    
    op = add; // Function pointer
    
    iRes = (int * )op( &x, &y );
    printf( "iRes = %d\n", *iRes );
    
    op = sub;
    iRes = (int * )op( &x, &y );
    printf( "iRes = %d\n", *iRes );
    
    return 0;
}