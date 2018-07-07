//Feb 11, 2017
//
//Demonstrates pointer differencing.
//Tells how far the pointers are from each other.
//
//mem address pi2 = 0x60104c   mem address of pi1 = 0x601048
//mem address pf2 = 0x60105c   mem address of pf1 = 0x601058
//
//difference is mem address is 1
//difference is mem address is 1
//
//Note that although the mem address is different by 4 bytes,
//the pointer difference says that these pointers are differ by 
//one index.
//
// Apr 26, 18      Pointer arithmetic is a difference in unit, not address.
//
#include <stdio.h>


int ia[4] = { 1, 222, 30, 4 };
float fa[4] = { 1.0, 222.0, 3121.0, 4.0 };

int
main(void)
{
    int *pi1 = &ia[2], *pi2 = &ia[3];
    float *pf1 = &fa[2], *pf2 = &fa[3];
    
    printf( "mem address pi2 = %p   mem address of pi1 = %p\n", pi2, pi1 );
    printf( "mem address pf2 = %p   mem address of pf1 = %p\n", pf2, pf1 );
    //this doesn't work!!!printf( "mem address pi2 = %ld   mem address of pi1 = %ld\n",pi2, pi1 );
    
    //Pointer differencing.
    printf( "difference is mem address is %ld\n", (pi2 - pi1) );
    printf( "difference is mem address is %ld\n", (pf2 - pf1) );
    
    return 0;
}