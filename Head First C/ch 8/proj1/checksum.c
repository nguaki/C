//checksum.c
#include "checksum.h"

int
checksum( char *msg )
{
    int total = 0;
    
    while( *msg ){
        total = total + total ^ (int)(*msg);
    
        msg++;
        //printf( "%i\n", total);
    }
    return total;
}