// April 5, 2017
//
// DESCRIPTION:
//    Demonstrates that int array is actually a pointer.
//
/***********************
0x7ffd8fc20bf0
1
0x7ffd8fc20bfc  (since size of int is 4 and 3*4=12, add 12 to 0x7ffd8fc20bf0 yields 0x7ffd8fc20bfc.)
4
4
==========================
0x7ffd8fc20bf0
1
0x7ffd8fc20bfc
4
4
**********************/
#include <stdio.h>

int
main(void)
{
    int a[5] = {1,2,3,4,5};
    
    int *p = a;
    
    printf( "%p\n", a );
    printf( "%d\n", *a );
    printf( "%p\n", a + 3 );
    printf( "%d\n", a[3]);
    printf( "%d\n", *(a+3)); //This takes 2 steps.
                             // 1. Since () has precedence over *, it performs
                             //       pointer math.  a + 3 = address of a + 3*sizeof(type of a).
                             // 2. Now it does the dereferencing.  
    
    printf( "==========================\n" );
    
    printf( "%p\n", p );
    printf( "%d\n", *p );
    printf( "%p\n", p + 3 );
    printf( "%d\n", p[3]);
    printf( "%d\n", *(p+3));
   
    return 0;
}