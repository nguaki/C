//address of  pi = 0x7ffd939a9d24
//address of pi2 = 0x7ffd939a9d24
#include <stdio.h>

int
main(void)
{
   int num;
   int *pi, *pi2;
   void *pv;
   
   pi = &num;
   pv = pi; //Usage of void pointer as a generic pointer.  There is no compilation error.
   pi2 = (int *)pv;
   
   printf( "address of pi = %p\n", pi );
   printf( "address of pi2 = %p\n", pi2 );
   

   return 0;
}