//
//gcc -Iinclude_files test_code.c object_files/encrypt.o object_files/checksum.o -o test_code
//
#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int
main()
{
    char msg[] = "Talk to your friend.";
    
    encrypt( msg );
    
    printf( "encrypted to '%s'\n", msg );
    printf( "check sum = %i\n", checksum(msg) );
    
    encrypt( msg );
    
    printf( "decrypted to '%s'\n", msg );
    printf( "check sum = %i\n", checksum(msg) );
    return 0;
}