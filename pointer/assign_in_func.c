#include <stdio.h>
#include <stdlib.h>

void
set( int *x )
{
  *x = 10;
}

void
set_dp( int **x )
{
  **x = 100;
}
void
set_sp( int *x )
{
  *x = 1000;
}

void
set_sp1( int **x )
{
  int *i = malloc(sizeof(int));
  
  *i = 10000;
  
  *x = i;
}
int
main(void)
{
    int i = 0;
    int *pi = NULL;
    int *pi1 = NULL;
    
    set( &i );
    printf( "i = %d\n", i );

    pi = &i;
    set_dp( &pi );
    printf( "i = %d\n", i );
    
    set_sp( pi );
    printf( "i = %d\n", i );
    
    set_sp1( &pi1 );
    printf( "%d\n", *pi1);
    
    return 0;
}