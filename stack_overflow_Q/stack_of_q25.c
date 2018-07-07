#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
}PIXEL;

void
Reassign( PIXEL **dp )
{
    int i, j, k = 0;
    for( i=0; i<2; i++)
        for( j=0; j<2; j++)
        {
            dp[i][j].R = i * j * k;
            dp[i][j].G = i * j * k + 1;
            dp[i][j].B = i * j * k + 2;
            dp[i][j].A = i * j * k + 3;
            k++;
        }
}

//
// Transformation of 3x3 array into a single long array.
//
void
print_tripleDim( void *tripleDim )
{
    int i, j, k;
    
    int *a = (int *)tripleDim;
    
    for( i = 0; i <9; i++)
        printf( "%d\n", a[i] );
}

int
main(void)
{
    PIXEL pixel1, pixel2, pixel3, pixel4;
    PIXEL **dp, pixel, p_array[2][2], *sp;
    FILE *fp;
    int i,j, k, iCnt, ***triplePointer;
    
    int tripleDim[3][3][3];
    
    iCnt = 0;
    for( i=0; i<3; i++)
        for( j=0; j<3; j++)
            for( k=0; k<3; k++)
                tripleDim[i][j][k] = iCnt++;
    print_tripleDim( tripleDim );


    triplePointer = malloc( 3 * sizeof(int **));
    
    for( i=0; i<3; i++){
        triplePointer[i] = malloc( 3 * sizeof( int *));
            for( j=0; j<3; j++)
                       triplePointer[i][j] = malloc( 3 * sizeof( int ));
    }
        
    printf( "iCnt = %d\n", iCnt);
    for( i=0; i<3; i++)
        for( j=0; j<3; j++)
            for( k=0; k<3; k++)
                    triplePointer[i][j][k] = iCnt++;
                    
    printf("===============================================\n");
    for( i=0; i<3; i++)
        for( j=0; j<3; j++)
            for( k=0; k<3; k++)
                printf( "%d\n", triplePointer[i][j][k]);
                

    print_tripleDim( triplePointer );

    
    pixel1.R = 5;
    pixel1.G = 5;
    pixel1.B = 5;
    pixel1.A = 5;

    pixel2.R = 7;
    pixel2.G = 7;
    pixel2.B = 7;
    pixel2.A = 7;
    
    pixel3.R = 9;
    pixel3.G = 9;
    pixel3.B = 9;
    pixel3.A = 9;
    
    pixel4.R = 11;
    pixel4.G = 11;
    pixel4.B = 11;
    pixel4.A = 11;
    
    fp = fopen( "pixel1", "wb");
    fwrite( &pixel1, sizeof(pixel1), 1, fp );
    fwrite( &pixel2, sizeof(pixel1), 1, fp);
    fwrite( &pixel3, sizeof(pixel1), 1, fp );
    fwrite( &pixel4, sizeof(pixel1), 1, fp );
    fclose( fp );
    
    fp = fopen( "pixel1", "rb");
    
    sp = malloc( 2 * 2* sizeof(PIXEL) );
    
    //for( i = 0; i < 2; i ++ )
    //{
        dp = malloc( 2 * sizeof(pixel));
        for( j = 0; j < 2; j ++ ){

            p_array[i][j] = pixel;
            //sp[k++] = pixel;
            //*(sp+k) = pixel;
            //k++;
            dp[j] = malloc( sizeof(pixel));
        }
    
    for( i = 0; i < 2; i++ )
        for( j = 0; j < 2; j ++ )
        {
            fread( &pixel, sizeof(PIXEL), 1, fp );
            printf( "%u\n", pixel.R);
            printf( "%u\n", pixel.G);
            printf( "%u\n", pixel.B);
            printf( "%u\n", pixel.A);

           dp[i][j] = pixel;
           //free(sp);
        }
    for( i = 0; i < 2; i++ )
        for( j = 0; j < 2; j ++ )
        {
            printf( "%u\n", dp[i][j].R);
            printf( "%u\n", dp[i][j].G);
            printf( "%u\n", dp[i][j].B);
            printf( "%u\n", dp[i][j].A);

           //free(sp);
        }
        
    Reassign( dp );
    
    printf( "=======================================\n" );
    for( i = 0; i < 2; i++ )
        for( j = 0; j < 2; j ++ )
        {
            printf( "%u\n", dp[i][j].R);
            printf( "%u\n", dp[i][j].G);
            printf( "%u\n", dp[i][j].B);
            printf( "%u\n", dp[i][j].A);

           //free(sp);
        }

    fclose(fp);
            
    return 0;
}