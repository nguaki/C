//100
//100
#include <stdio.h>

int
main(void)
{
    int num = 100;
    const int *const a = &num;   //Must initialize and declare simultaneously.
                                 //  Cannot modify the address nor use it as a lvalue.
                                      
    const int *const *b = &a;    //Now this acts as a pointer to above variable.
    
    printf( "%d\n", *a );
    printf( "%d\n", **b );
    
    return 0;
}