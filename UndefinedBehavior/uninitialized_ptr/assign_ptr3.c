//////////////////////////////////////////////////////////////////////////////////
//
// assign_ptr3.c
//
// OUTPUT:
//  memory address of q = 0x7ffde4cf7194
//  memory address of p = 0x7fff7df288d4
//  Segmentation fault
//
//Explanation:
//  The variable is assigned a memory address.  But why it is getting a segmentation
//  fault?
//  My understanding is that the assigned mem address is not writable for
//  an integer value.
//  In order to do this correctly, use malloc().
//
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>


int
main(void)
{
    int q;
    int *p = (int *)0x7fff7df288d4;
    
    printf("memory address of q = %p\n", &q );
    printf("memory address of p = %p\n", p );
    
    *p = 100;

    return 0;
}