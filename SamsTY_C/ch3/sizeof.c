//Feb 11, 2017
//
//Prints out size of each variable type.

/*
sizeof char = 1
sizeof short = 2
sizeof int = 4
sizeof long = 8
sizeof long long = 8
====================================================
sizeof unsigned char = 1
sizeof unsigned short = 2
sizeof unsigned int = 4
sizeof unsigned long = 8
sizeof unsigned long long = 8
====================================================
sizeof float = 4
sizeof double = 8
sizeof long double = 16
*/
#include <stdio.h>

void
main()
{
    //Note that sizeof() returns unsigned long int.
    printf( "sizeof char = %lu\n", sizeof(char) );
    printf( "sizeof short = %lu\n", sizeof(short) );
    printf( "sizeof int = %lu\n", sizeof(int) );
    printf( "sizeof long = %lu\n", sizeof(long) );
    printf( "sizeof long long = %lu\n", sizeof(long long) );

    printf( "====================================================\n" );
    printf( "sizeof unsigned char = %lu\n", sizeof(char) );
    printf( "sizeof unsigned short = %lu\n", sizeof(short) );
    printf( "sizeof unsigned int = %lu\n", sizeof(int) );
    printf( "sizeof unsigned long = %lu\n", sizeof(long) );
    printf( "sizeof unsigned long long = %lu\n", sizeof(long long) );

    printf( "====================================================\n" );
    printf( "sizeof float = %lu\n", sizeof(float) );
    printf( "sizeof double = %lu\n", sizeof(double) );
    printf( "sizeof long double = %lu\n", sizeof(long double) );

}