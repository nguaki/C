#include <stdio.h>
#include <stdlib.h>

void add_cells( int board[5][5] )  // <=== This is same as passing a reference.
{
   int *p;
   int i;
   
  // p = (int *)board;
    p = (int *)board;  //Converting to single array.
  
   for( i = 0; i < 25; i ++ )
       p[i] = i;
}

void
modify( int k )
{
    k = 10;
}

int
main(void)
{
   int x[5][5];
   int i,j,k;
   
   modify( i );
   
   for( i = 0; i <5; i++ )
    for( j = 0; j < 5; j++ )
        x[i][j] = 0;
    for( i = 0; i <5; i++ )
    for( j = 0; j < 5; j++ )
        printf( "%d\n", x[i][j] );
        
    add_cells( x );            
 
    for( i = 0; i <5; i++ )
    for( j = 0; j < 5; j++ )
        printf( "%d\n", x[i][j] );
  

   return 0;
}