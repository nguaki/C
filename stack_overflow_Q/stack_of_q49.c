#include <stdio.h>
#include <string.h>

int 
main(void)
{
    char x[100];
    char *cp;
    
    strcpy(x, "AAA  BBB CCCC DDDD" );
    
    cp = strtok(x, " ");
    
    while(cp)
    {
        printf( "%s\n", cp );
        cp = strtok(NULL, " ");
    }
    
    return 0;
}