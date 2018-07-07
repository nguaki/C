//////////////////////////////////////////////////////////////////////
//April 1, 2017
//
// assign_ptr4.c
//
//Demonstration of pointer to integer declaration and assignment.
//This only works for a single scalar number, not for an array.
//
//OUTPUT
//memory address of q = 0x7fff1bafdbac
//memory address of p = 0x7fff1bafdbb0
//dereference of p is 42
//dereference of p is now 100
//
//////////////////////////////////////////////////////////////////////
#include <stdio.h>


int
main(void)
{
    int q;
    int *p = &(int){42}; //This is a way to assign a value and the pointer
                         //address at the same time.
      
    //Note that the following statement is not allowed in C since
    //the committe of C programming language did not bother to
    //create a short cut for pointer to integer initialization.
    //int *myInts = &(int){100, 6, 1, 2, 3, 8, 4, 1, 7, 2};         
    
    int i = 0;
    
    //for( i=0; i<9; i++ )
    //    printf("%d\n", myInts[i] );
        
    printf("memory address of q = %p\n", &q );
    printf("memory address of p = %p\n", p );
    printf("dereference of p is %i\n", *p);
    
    *p = 100;  //Apparently 
    printf("dereference of p is now %i\n", *p);

    return 0;
}