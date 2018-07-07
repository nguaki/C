.//100
//
#include <stdio.h>

int
main(void)
{
    int num = 100;
    const int *const a = &num;   //Must initialize and declare simultaneously.
                                 //  Cannot modify the address nor use it as a lvalue.
                                      
    printf( "%d\n", *a );
    
    return 0;
}