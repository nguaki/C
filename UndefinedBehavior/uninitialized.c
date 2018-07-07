//////////////////////////////////////////////////////////////////
// March 28, 17
//Ususally, unassigned int variable generates unexpected results.
//When compiled with gcc, it consistenly generate same result.
//However, different OS or compiler can generate UB.
//output
//x=0
//////////////////////////////////////////////////////////////////
#include <stdio.h>


int
main(void)
{
    int x;
    
    printf( "x=%d\n", x);

    return 0;
}