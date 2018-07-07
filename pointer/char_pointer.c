// April 5, 17
//
// EXPLANATION:
//    This is a demonstration of pointer of char also works with
//    char variable.  All this time, pointer to character worked
//    with string.
//
// OUTPUT
//     cp = a

#include <stdio.h>

int
main(void)
{
    char c = 'a';
    
    char *cp;
    
    cp = &c;
    
    
    printf("cp = %c\n", *cp);
    return 0;
}