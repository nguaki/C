#include <stdio.h>
#include <stdlib.h>

long 
lFactorial( unsigned int ui )
{
    long lRes;
    
    if( ui == 1 ) return 1;
    
    //lRes = ui * lFactorial( ui - 1 );
    //return lRes;
    return( ui * lFactorial( ui - 1 ));
}
    
int
main( int argc, char *argv[])
{
    unsigned int uiX;
    long         lFact;
    
    printf("Enter a positive number:");
    scanf("%u", &uiX);
    
    //printf( "uiX = %u", uiX );
    printf( "%ld ", lFactorial( uiX ) );
    
    return 1;
}



