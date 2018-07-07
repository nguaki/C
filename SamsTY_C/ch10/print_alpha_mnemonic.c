#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    char *pcAlpha, *pc;
    int  iASCII;
    
    pcAlpha = malloc( (26+1)*sizeof(char) );
    
    pc = pcAlpha;
    
    for( iASCII = 65; iASCII < 91; iASCII++ )
        *pc++ = iASCII;
        
    *pc = '\0';
    
    printf( "%s\n", pcAlpha );
    
    return 1;
}