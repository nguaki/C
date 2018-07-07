#include <stdio.h>
#include <string.h>

int
main(void)
{
    char pattern[32] = "%3s", caString[32];
    sscanf("hello",pattern,caString);
    
    printf("%s\n", caString );

    return 0;
}