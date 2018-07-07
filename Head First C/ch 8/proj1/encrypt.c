//encrypt.c

#include "encrypt.h"

void 
encrypt( char *msg )
{
    //For some reasons *msg++ caused error.
    while( *msg ){
        *msg = *msg ^ 31;
        msg++;
    }
}