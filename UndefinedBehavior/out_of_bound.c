//64
#include <stdio.h>

int
main(void)
{
    char a[10];
    printf("%d", a[10]);  // Bang
    a[-1] = 7;  // Oww!
    
    return 0;
}