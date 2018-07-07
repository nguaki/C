#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int array[3][3] = { 1, 2, 3,
			    4, 5, 6,
			    7, 8, 9 };

	printf( "value stored at array = %p memory address of array = %p\n", array, &array ); 
	printf( "value stored at array[0] = %p memory address of array = %p\n", array[0], &array[0] ); 

    int *ip;
    int j;
    ip = &array;
    
    for( j=0; j<9; j++)
    	printf( "%d\n", *ip++ );
    
	return 0;
}
