#include <stdio.h>
#include <stdlib.h>

void showRow(void *array, int rowNumber, int nColsInRow)
{
    int (*a)[10] = (int (*)[10])array;
    int i;
    for (i=0; i < 10; i++) {
        printf("%d\n", a[rowNumber][i]);
    }

}

int main()
{
    int array[10][10];
    int i,j;


    int add = 0;

    for(i = 0; i < 10; i++)
    {
       for(j = 0; j < 10; j++)
       {   
           array[i][j]= add;
           add++;

       }

    }

    showRow (&array, 5, 10);

    return 0;
}