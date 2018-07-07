#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void
vDisplay( int **ipp )
{
    int i,j;
    
    for( i=0; i<SIZE; i++){
        for( j=0; j<SIZE; j++){
            printf( "%d  ", ipp[i][j]);
        }
        printf("\n");
    }
}

//void transposeMatrix(int m,int n,int mtr[m][n])
void transposeMatrix(int m,int n,int **mtr)
{
    int temp[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][j]=mtr[i][j];
        }
    }
    for(int i=0;i<m;i++)
        free(mtr[i]);
    //free(mtr);
    //mtr=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
        mtr[i]=(int *)malloc(m*sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mtr[i][j]=temp[j][i];
        }
    }
}

int
main(void)
{
    int **ipp;
    int iRow = 3;
    int iCol = 3;
    int i, j, k = 0;
    
    ipp = malloc(iRow * sizeof(int *) );
    
    for( i=0; i<iRow; i++)
        ipp[i] = malloc(iCol * sizeof(int));
            
    for( i=0; i<iCol; i++ )
        for( j=0; j<2; j++)
            ipp[i][j] = k++;
            
    vDisplay( ipp );
    transposeMatrix(iRow,iCol, ipp);
    vDisplay( ipp );

    return 0;
}
            
    