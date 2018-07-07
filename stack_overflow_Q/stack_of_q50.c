#include <stdio.h>

int
main(void)
{
int array[100];
int i = 0, j;

while(i < 100 && scanf("%d\n", &array[i]) == 1)
    i++;
    
    
    for( j =0; j < i; j++ )
        printf( "%d ", array[j]);
        
    return 0;
}