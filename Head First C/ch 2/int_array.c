///////////////////////////////////////////////////////////////////
//Jan 20, 2017
//
// Illustrates the int pointer of an array
// points to array[0].
//
//OUTPUT:
//I pick contestant 2
///////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iContestants[3] = { 1, 2, 3 };
    
    int *iContestant;
    
    iContestant = iContestants; //Same as iContestant = &iContestants[0];
    //iContestant = &iContestants[0]; //Same as iContestant = &iContestants[0];
    
    iContestants[0] = 2;
    iContestants[1] = iContestants[2];
    
    //Below statement assigns value of 2.
    iContestants[2] = *iContestant;     //This is same assignment as iContestants[0].
    
    printf( "I pick contestant %i\n", iContestants[2] );

    return 0;
}