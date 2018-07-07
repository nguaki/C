/*
Feb 16, 17

Demonstration of array of pointers to type char


OUTPUT
one
two
three
four
five
six
seven
eight

April 28, 18   Added comments. Frees up memory

*/
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////
//Apr 28, 18
//The following 2 are the same as far as the compiler is concerned since
//compilation decays in char **p_ca.
//But for the readability reason, the first one is preferred.
//So be very careful *p_ca[] and **p_ca are identical in the context
//of arguement but not initialization.
//At initialization, ther are not interchangeable.
/////////////////////////////////////////////////////////////////////////////
void
//vPrintStrings( char *p_ca[] )
vPrintStrings( char **p_ca )  //Getting the mem address of the 1st indice.
{
    int i;
    
    for( i=0; i<8; i++)
        printf( "%s\n", p_ca[i] );

}

int
main(void)
{
    char *p_c_array[] = { "one", "two", "three", "four", "five", "six", "seven", "eight" };
    
    //The following doesn't work.
    //char **p_c_array = (void*){ "one", "two", "three", "four", "five", "six", "seven", "eight" };
     
    //p_c_array[0][1] = 'P';  <==Causes seg fault since it is trying to modify read only memory.
    
    vPrintStrings( p_c_array );


    return 0;
}