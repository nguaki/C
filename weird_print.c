//April 4, 17
//
//EXPLANATION:
// Conditional print statement.
//
//OUTPUT
//d
//
// Remember ASCII value of 100 is the letter 'd'.
#include <stdio.h>

int
main(void)
{

    int a = 100, b = 70;
    
    //Below statement is same as 
    //if( a< b )
    //    printf("%d", a );
    //else
    //    printf("%c", a );
    printf( (a<b)?"%d":"%c", a );
    
    
    return 0;
}
