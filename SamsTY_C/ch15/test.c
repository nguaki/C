#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int i;
	int *pi;
	int **ppi;

 	i = 10;
	pi = &i;
	ppi = &pi;

	printf( "value stored in  i    = %d  memory location of i = %p\n", i, &i );
	printf( "value stored in  pi   = %p  memory location of address of pi  = %p\n", pi, &pi );
	printf( "value stored in  ppi  = %p  memory location of address of ppi = %p\n", ppi, &ppi );

	return 0;
}
