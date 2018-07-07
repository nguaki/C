// Jan 20 ,2017
//
// Illustrates weird aspect of C.
//  iDoses[2] = 2[iDoses]
//  The following pointer arithmetic applies.
//
//  iDoses[2] = *(iDoses + 2) = *(2 + iDoses) = 2[iDoses]
//
//OUTPUT
//100
//100
//100
//100

#include <stdio.h>
#include <string.h>

int
main()
{
    int iDoses[] = { 1, 2, 100 };
    
    
    printf( "%i\n", 2[iDoses] );
    printf( "%i\n", *(2+iDoses));  //<==Pointer arithmetic

    printf( "%i\n", iDoses[2] );
    printf( "%i\n", *(iDoses+2));  //<== Pointer arithmetic
    return 0;
}