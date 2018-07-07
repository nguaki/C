#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    float **f2Darray;
    int i, j;
    int RCnt, CCnt;
    float *fp;
    
    f2Darray = malloc( 10 * sizeof(float * ) );
    
    for( i = 0; i < 10; i ++ )
        f2Darray[i] = malloc(10 * sizeof(float) );

    printf( "sizeof f2Darray = %u\n", sizeof(f2Darray) );
    printf( "sizeof f2Darray[0] = %u\n", sizeof(f2Darray[0]));
    
    for( i = 0; i < 10; i++)
        for( j = 0; j < 10; j++)
            f2Darray[i][j] = 10.0;
            
    RCnt = 0;
    CCnt = 0;
    
    fp = f2Darray[0];
    i = 0;
    j = 0;
    while(f2Darray[i][j] > 5.0){
        i++;j++;
    }   
    printf( "RowCnt = %d  ColCnt = %d\n", i, j);
            
    return 0;

}