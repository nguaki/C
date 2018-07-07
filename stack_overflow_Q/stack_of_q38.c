/*
Prior to applying the ~ operator, the value of u8a is promoted to int. 
So assuming an int is 4 bytes the value 0xff is promoted to 0x000000ff. 
Applying the ~ operator to that yields 0xffffff00.

So when you print this value using the %d operator, it is interpreted 
(rightfully) as -256. Similarly, this value is not the same as 0x00, so "Not Equal" is printed.

To get the result you expect, you need to cast the result of the ~ operator 
back to uint8_t. Also, you should use the %hhu format specifier to printf to 
accurately reflect the value you're passing in.
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int
main(void)
{
    uint8_t u8a;
    
    u8a = 0xff;
    
    printf( "%hhu\n", (uint8_t)~u8a );
    printf( "%" PRIu8 "\n", (uint8_t)~u8a );  //PRIu8 is a macro 

    if( (uint8_t)~u8a == 0x00 )
        printf( "Equal\n" );
    else
        printf( "Not Equal\n" );
    
    return 0;
}