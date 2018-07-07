//Apr 26, 18 Mnemonic
//
//
#include <stdio.h>
#include <stdlib.h>

long
lGetPower3( unsigned int uiBase )
{
    static int iCnt = 3;
    
    if( iCnt == 1 ) return uiBase;
    iCnt--;
    return uiBase * lGetPower3(uiBase);
    
}
int
main( int argc, char *argv[] )
{
    unsigned int uiBase;
    
    scanf("%u", &uiBase );
    printf( "%ld\n", lGetPower3(uiBase));
    
    return 1;
}