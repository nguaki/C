// cp1 and cp2 point at same address since reallocation was smaller than original 
// allocation.
//0x196e010 --- Hello
//0x196e010 --- Hello
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    char *cp1, *cp2;
    
    cp1 = malloc(16);
    
    strcpy( cp1, "Hello World" );
    
    cp2 =realloc( cp1, 5 );
    cp2[5] = 0;
    printf("%p --- %s\n", cp1, cp1 );
    printf("%p --- %s\n", cp2, cp2 );
    
    return 0;
}