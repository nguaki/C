//March 31, 2017
//
//OUTPUT:
//Segmentation fault
//
//Here is my understanding:
//int *p = NULL
#include <stdio.h>

int
main(void)
{
    //int *p = NULL;
    //int *p = 300;
    int *p;
    int q;
    
    
    printf( "address of p is %p\n", p);
    printf( "address of q is %p\n", &q );
    
    p = &q;
    printf( "address of p is now %p\n", p);
    
    *p = 123;  // Kaboom
    
    return 0;
}