#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int
iOddOne( int *iArray, int iSize )
{
	int iRes = 0;
	int i;

	for( i=0; i<iSize; i++ )
		iRes = iRes ^ iArray[i];

	return iRes;	
}

int
main(void)
{
	int iArray[10] = { 2, 3, 4, 2, 3, 4, 5 };

	printf( "%d\n", iOddOne(iArray, 7));

	assert( iOddOne( iArray, 7 ) == 5 );
	return 1;
}
