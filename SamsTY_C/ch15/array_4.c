//Feb 17, 17
//
//Demonstrates pointer to an array of 4 of integer.
//
//1       2       3       4
//5       6       7       8
//9       10      11      12
//9       10      11      12
//
// Important distinction between
//   int *A[4];     <=== Array of 4 of pointers to int
//   int (*A)[4];   <=== pointer to array of 4 int
//
//   int *A[4]   looks like
//           A[0],A[1],A[2],A[3]  has memory address
//   int A has a single memory address.
//   When A increments, it moves by 4x4=16 bytes.
//
//   Looks similar but very different.
//
//   Apr 28, 18    Added comments to distinguish between int (*A)[4] vs int *A[5].
//
#include <stdio.h> 

//The following 2 are stored the same way internally since array are 
//stored in a continuous memory.

/*
int a[3][4] = { 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12 };
*/

int a[3][4] = { { 1, 2, 3, 4 },
                { 5, 6, 7, 8 },
                { 9, 10, 11, 12 } };
 
//The arguement takes in a pointer to an array of 4 of integers.
void print_array( int (*xyz)[4] )
{
    int *p_i;
    int i;
    
    //p_i is a pointer to an integer.
    //xyz is a pointer to tan array of integer.
    //So there is a difference in the type.
    //So typecast is required.
    p_i = (int *)xyz;  
    
    for( i=0; i<4; i++)
        printf( "%d\t", *p_i++ );  //Dereference first and then move to next integer address.
        
    puts("");
    
}

//The arguement takes in a pointer to an array of 4 of integers.
void print_array1( int (*xyz)[4] )
{
    int *p_i;
    int i, j;
    
    p_i = (int *)xyz;
    
    //This will print out entire array
    for( i=0; i<4; i++)
            printf( "%d\t", *p_i++ );
    
    puts("");
}
int
main(void)
{
    int (*p_i4)[4];
    int i;
    
    p_i4 = a;
    
    for( i = 0; i < 3; i ++ )
        print_array( p_i4++ );//Passes the address of the array of int of 4 and
                              //then moves to next array of int of 4.
                              //So in this case, the address change is 4*4=16 bytes
                              //forward.
        
    p_i4 = (void *)&a[2];  //(void *)removes compilation error.
    
    print_array1( p_i4 ); //Passes in address of last array of 4 of integer.
    
    return 0;
}