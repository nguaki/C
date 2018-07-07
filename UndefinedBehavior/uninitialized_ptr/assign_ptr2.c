///////////////////////////////////////////////////////////////
//
//OUTPUT:
//   memory address of p = (nil)
//   Segmentation fault
//
//EXPLANATION:
//     Above indicates that the variable p has no memory location.
//     The statement *p = 100; generates seg fault since
//     it is trying to store a value from a location that 
//     is not defined.
//
///////////////////////////////////////////////////////////////////
#include <stdio.h>


int
main(void)
{
    int *p = NULL;
    
    printf("memory address of p = %p\n", p );
    
    *p = 100;

    return 0;
}