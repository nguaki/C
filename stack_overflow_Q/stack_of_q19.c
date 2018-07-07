#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    FILE *fp;
    
    if( ( fp = fopen( "nonexistfile", "r" ) )== NULL ){
        exit(5);
    }
    
    if(fp) fclose(fp);
    
    return 0;
}