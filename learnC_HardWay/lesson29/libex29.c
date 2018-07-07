//  March 7, 2017  
//.
//  Create a shared library
//
//  cc -c -fPIC libex29.c -o libex29.o
//  cc -shared -o libex29.so libex29.o
//
#include <stdio.h>
#include "dbg.h"
#include <stdlib.h>

int print_a_message( const char *msg )
{
    printf( "A message: %s\n", msg );
    
    return 0;
}

int uppercase( const char *msg )
{
    int i = 0;
    
    for( i=0; msg[i] != '\0'; i++)
        printf( "%c", toupper(msg[i]));

    return 0;
}

int lowercase( const char *msg )
{
    int i = 0;
    
    for( i=0; msg[i] != '\0'; i++)
        printf( "%c", tolower(msg[i]));

    return 0;
}

int fail_on_purpose( const char *msg )
{
    return 0;
}
