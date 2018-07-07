//////////////////////////////////////////////////////////////////////////
// April 5, 2016
//
// EXPLANATION:
//   Becareful on the difference between '0' and '\0'.
//   '0' is a character for zero.
//   '\0' is a character that represents string NUL.
//
// OUTPUT:
//ca = ab0d
//ca = ab
//////////////////////////////////////////////////////////////////////////
#include <stdio.h> 


int
main(void)
{
    char ca[5] = "abcd";
    char *p;
    
    p = ca + 2;
    *p = '0';
    
    printf( "ca = %s\n", ca );
    
    *p = '\0';
    printf( "ca = %s\n", ca );
   
    return 0;
}