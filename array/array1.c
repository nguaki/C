//size of array = 5 <== true size of an int array
//size of array = 8 <== size of int *
//
// Apr 25,18   Added comment.
#include <stdio.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////
// Apr 25, 18
// Note that after compilation,  (int array[]) decays to (int *array).
// So array is actually a pointer to int.
//////////////////////////////////////////////////////////////////////
void
display( int array[] )
{
    printf("size of array = %lu\n", sizeof(array) );
}

int
main(void)
{
    int array[5] = { 1, 2, 3, 4, 5 };
    
    printf("size of array = %lu\n", sizeof(array)/sizeof(int) );
    display(array);
    return 0;
}
