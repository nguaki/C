//8
//8
//8
#include <stdio.h>

int
main(void)
{
    size_t size;  //size_t is type of unsigned int
    
    size = sizeof(void *);
    
    printf( "%zd\n", size );
    printf( "%zd\n", sizeof( int *) );
    printf( "%lu\n", sizeof( int *) ); //sizeof return long unsigned int
    
    return 0;
}