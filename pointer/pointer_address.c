/*
April 4, 17

FILENAME: pointer_address.c

Description:
Here is a way to print the memory address.
%p prints out hexadecimal.
%u unsigned decimal
%d signed decimal.

Using %d for signed decimal doesn't make a sense since memory address
can never be negative.

Need to use %u format specifier for decimal memory address.
%d is for signed integer and sometimes the number overflows.

0x7fff02b4d664
45405796
45405796
dguai:~/workspace/C $ ./a.out
0x7fff48716284
1215390340
1215390340
dguai:~/workspace/C $ ./a.out
0x7ffc90353a64
2419407460
-1875559836  <== negative address?  This can't be!!!
*/

#include <stdio.h>

int
main(void)
{

    int x = 100;
    int *y;
    
    y = &x;
    
    printf( "%p\n", y );
    printf( "%u\n", y );
    printf( "%d\n", y );
    
    return 0;
}
