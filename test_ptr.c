#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char *cp = "abcdefg";
    
    //cp[0] = 'A';
    *cp = 'A';
    printf( "%s\n", cp );
    
    return 0;
}