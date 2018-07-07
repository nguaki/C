/////////////////////////////////////////////////////////////////////////////
// Jan 20, 17
//
// Illustrates advantage of fgets() over scanf().
//
// There are 2 advantages of fgets() over scanf().
// 1. If the size of input is greater than what is allowed,
//    it does not cause seg fault in fgets() where in scanf() causes 
//    seg fault.
// 2. fgets() allow a space as an input.
//
//
// scenario 1: Enter input who's data size is greater than what is allocated.
//             
//What is the color name:afdafda  <== Doesn't cause seg fault.
//Color:afda
//
//
// scenario 2: Enter a space as an input.
//What is the color name:a de
//Color:a de   <=== accepts a space as an input
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int
main()
{

    char caColor[5];
    

    printf( "What is the color name:");
    fgets( caColor, sizeof(caColor), stdin);
    
    printf( "Color:%s\n", caColor);
    return 0;
}