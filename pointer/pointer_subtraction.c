//2
//3   <==== difference of units
//
// it looks like memory address subtraction.  But pointer subtraction
// returns the difference in the units.
//
#include <stdio.h>

int
main(void)
{
   int ia[] = { 4, 5, 7, 8 };
   
   int *p3, *p1, *p0;
   
   p3 = &ia[3];
   p1 = &ia[1];
   p0 = &ia[0];
   
   printf( "%ld\n", p3 - p1 );
   printf( "%ld\n", p3 - p0 );
   
   return 0;
}