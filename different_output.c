//-5
//4294967291
//
//size_t is of unsigned int.
// assigning -5 should be an error in first place.
//
// %d specifier expects signed number.  So the highest bit is a signed bit.
// %u specifier expects unsigned number.  So the highest bit is a highest power number.
#include <stdio.h>

int
main(void)
{
    size_t t;
    
    t = -5;
    
    printf( "%d\n", t );
    printf( "%u\n", t );
    
    return 0;
}