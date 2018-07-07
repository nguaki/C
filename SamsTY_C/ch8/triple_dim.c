//
// Feb 11, 17
//
// Demonstrates the usage of getchar().
//
// Apr 26, 18      Added if C == 'q' then exit.
//
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int a[10][10][10];
    int i,j,k;
    char C;
    
    for( i = 0; i < 10; i++ )
        for( j = 0; j < 10; j++ )
            for( k = 0; k < 10; k++ )
                a[i][j][k] = rand();
    
     for( i = 0; i < 10; i++ )
        for( j = 0; j < 10; j++ ){
            for( k = 0; k < 10; k++ )
                printf( "a[%d][%d][%d] = %d\n", i,j,k,a[i][j][k] );
            
            printf( "Ctrl-C to quit\n" );
            C = getchar();
            if (C=='q') exit(1);
        }


    return 0;
}