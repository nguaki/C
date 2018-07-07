///////////////////////////////////////////////////////
// levels_redirection.c
//
// April 4, 2017
//
// DESCRIPTION:
//    ANSI-C allows 12 levels of indirections.
//
// OUTPUT:
//i = 5
//i = 10
///////////////////////////////////////////////////////

#include <stdio.h>

int
main(void)
{

    int i = 5;
    printf( "i = %d\n", i );
    
    int *i1 = &i;
    int **i2 = &i1;
    int ***i3 = &i2;
    int ****i4 = &i3;
    int *****i5 = &i4;
    int ******i6 = &i5;
    int *******i7 = &i6;
    int ********i8 = &i7;
    int *********i9 = &i8;
    int **********i10 = &i9;
    int ***********i11 = &i10;
    int ************i12 = &i11;

    ************i12 = 10;
    printf( "i = %d\n", i );
    
    return 0;
}
