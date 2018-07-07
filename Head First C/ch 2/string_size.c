/////////////////////////////////////////////////////////////////////////
//Date: Jan 20, 2017
//
// OUTPUT:
//messages is Cookies make you fat.
//
//sizeof(msg) = 8   <== this is 8 since the size of char msg[] is same as size 
//of char *.
//strlen(msg) = 22
//sizeof(p)   = 8
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fortune_cookie( char msg[] )
{
    char *p;
    
    fprintf( stdout, "messages is %s\n", msg );
    fprintf( stdout, "sizeof(msg) = %i\n", (int)sizeof(msg) );
    fprintf( stdout, "strlen(msg) = %i\n", (int)strlen(msg) );
    fprintf( stdout, "sizeof(p)   = %i\n", (int)sizeof(p) );
}

int main()
{

    char msg[] = "Cookies make you fat.\n";
    
    fortune_cookie( msg );
    
    return 0;
}