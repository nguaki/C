////////////////////////////////////////////////////////////////////
//April 5, 2017
//
//EXPLANATION:
//  Pointer arithmetic is not allowed to int array variable.
//  This is the major difference between pointer and int array.
//
//OUTPUT:
//dguai:~/workspace/C/pointer_array $ gcc pointer_arith_to_array.c 
//pointer_arith_to_array.c: In function ‘main’:
//pointer_arith_to_array.c:19:7: error: incompatible types when assigning to type ‘int[5]’ from type ‘int *’
//     a = a + 2;
//
////////////////////////////////////////////////////////////////////
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
    
    a = a + 2;  // <=== This causes an error.
                //pointer_arith_to_array.c:19:7: error: incompatible types when assigning to type 
                //‘int[5]’ from type ‘int *’
                //a = a + 2;

    
    printf( "==========================\n" );
    
    printf( "%p\n", p );
    printf( "%d\n", *p );
    printf( "%p\n", p + 3 );
    printf( "%d\n", p[3]);
    printf( "%d\n", *(p+3));
   
    return 0;
}