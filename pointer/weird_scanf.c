//////////////////////////////////////////////////////////////////
//April 4, 2017
//
//Description:
// Uses pointer to integer to enter data.
//
//Explanation:
//  Usually scanf() works like this.
//        scanf( "%d", &i);
//        Memory address needs to be specified.
//
//        Lets suppose p is a pointer to int.
//            int *p;
//            p = &i;
//
//        So by substitution,
//        scanf( "%d", p ); is perfectly legal.
//
// OUTPUT:
//45
//i = 45
//////////////////////////////////////////////////////////////////

#include <stdio.h>

int
main(void)
{

    int i;
    int *p = &i;
    
    scanf("%d", p );
    
    printf( "i = %d\n", i );

    return 0;
}