// cp1 and cp2 point may or may not point at same address since cp2 allocated
// more than cp1.
// allocation.
//0x196e010 --- Hello World
//0x196e010 --- Hello World
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
    
    cp2 =realloc( cp1, 60 );
    //cp2[5] = 0;
    printf("%p --- %s\n", cp1, cp1 );
    printf("%p --- %s\n", cp2, cp2 );
    
    return 0;
}