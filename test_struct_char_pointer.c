#include <stdio.h>
#include <stdlib.h>

struct{
   char *name;
}A;

int
main(void)
{
    char *name;
    A.name = "Emily";
    name = "Emily";
    
    printf( "%s\n", A.name );
    printf(" %s\n", name );
    
    return 0;
}