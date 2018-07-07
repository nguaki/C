///////////////////////////////////////////////////////////////////////////
// OUTPUT:
// memory address of cp = 0x400634      <=== Read only memory
// memory address of p = 0x7ffea53a29fc
// Segmentation fault
//
//
//  gcc -g assign_ptr5.c -o assign_ptr
//  gdb assign_ptr
//  run
//  Segmentation fault occurs on this statement:
//         cp[0] = 'b';
//  Why?
//     char *cp = "hello";
//     
//   In C, the string "hello" is stored at memory location of 0x400634 
//   which is read only.  So, it is not modifiable.
//
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>

const int globalConstInt = 100;

int
main(void)
{
    char *cp = "hello";
    int *p = &(int){42};
    const int localConstInt = 50;
    
    printf("memory address of globalConstInt = %p\n", &globalConstInt );
    printf("memory address of localConstInt = %p\n", &localConstInt );
    printf("memory address of cp = %p\n", &cp[0] );
    printf("memory address of p = %p\n", p );
    //printf("dereference of p is %i\n", *p);
    
    cp[0] = 'b';   //<=== segment fault.
    *p = 100;
    printf("dereference of p is now %i\n", *p);

    return 0;
}