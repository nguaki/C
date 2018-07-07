#include <stdio.h>
#include <stdlib.h>

void showRow(int *array, int rowNumber, int nColsInRow);
void showCol(int *array, int colNumber, int nRowsInCol);


int 
main(void)
{

int array[10][10];
int i,j;
int *p;

p = (int *)array;
//int *row0, *row1, *row2, *row3, *row4, *row5, *temp;


int add = 0;

for(i = 0; i < 10; i++)
{
   for(j = 0; j < 10; j++)
   {   
       array[i][j]= add;
       add++;
   }
}


for(i = 0; i < 10; i++)
{
    for(j = 0; j < 10; j++)
    {
        printf("%d ", array[i][j]);
    }
    printf(" \n");

}
 printf("===============================\n");
 showRow( p, 0, 0);
 printf("===============================\n");
 showRow( p, 2, 3);
 printf("===============================\n");
 showRow( p, 3, 4);
 printf("===============================\n");
 showRow( p, 9, 9);
 printf("===============================\n");
 showCol( p, 5, 2);
 printf("===============================\n");
 showCol( p, 7, 3);
}

void showRow(int *array, int rowNumber, int nColsInRow)
{
    int *row = &array[rowNumber*10];
    int j;
    
    
    //printf( "%d\n", array[0][0] );
    
    for(j = 0; j < 10; j++)
    {
        printf(" %d", row[j]);

    }

    printf("\n%d\n", row[nColsInRow]);

} 

void showCol(int *array, int colNumber, int nRowsInCol)
{
    int *col = &array[colNumber];
    int j, n;
    for(j = 0; j < 100; j = j + 10)
    {
        printf(" %d", col[j]);

    }
    
    n = 10 * nRowsInCol;
    printf( "\n%d\n", col[n]);


}
