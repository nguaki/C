//Feb 17, 17
//
//Demonstration of fread() and fwrite() using binary mode.
//
/*
0       0
2       2
4       4
6       6
8       8
10      10
12      12
14      14
16      16
18      18
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int
main(void)
{
    FILE *fp;
    int  i, ia[MAX], ib[MAX];
    
    for( i=0; i<MAX; i++)
        ia[i] = 2 * i;
        
    if (( fp = fopen("direct.txt", "wb" ) ) == NULL ){
        printf( "error opening.\n" );
        exit(1);
    }
    
    if ( fwrite( ia, sizeof(int), MAX, fp) != MAX ){
        printf( "error writing.\n" );
        exit(1);
    }
    
    fclose(fp);
    
    if (( fp = fopen("direct.txt", "rb" ) ) == NULL ){
        printf( "error opening.\n" );
        exit(1);
    }
    
    if ( fread( ib, sizeof(int), MAX, fp) != MAX ){
        printf( "error writing.\n" );
        exit(1);
    }
    
    for( i=0; i<MAX; i++)
        printf( "%d\t%d\n", ia[i], ib[i] );
        
    return 0;
}