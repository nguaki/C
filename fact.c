#include <stdlib.h>
#include <stdio.h>


int
fact( int n )
{
	if (n==1) return 1;
	return n + fact(n-1);
}

int
main(void)
{
	int iNumYears = 1;

	for( unsigned int iDays = 365; iNumYears <=30; iDays += 365, iNumYears++ )
		printf( "After %d year ==> %d\n", iNumYears, (int)(fact(iDays)/100 ));

	return 0;
}
