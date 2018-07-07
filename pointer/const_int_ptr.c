//
//
//100
//200
//200
//100
//100

#include <stdio.h>

int
main(void)
{
    int num = 100;
    int *ip;
    const int cnum = 200;
    const int *cip;  // cip is a pointer to const int.
                     //     (1) It cannot be used to change to value.
                     //         In other words, it cannot be used as lvalue.
                     //  *cip = 200;  <=== Illegal
    
    int const *cip2;  //The order of const and int do not matter.
    
    ip = &num;
    
    cip = &cnum;  
    cip2 = &cnum;
    
    printf( "%d\n", *cip );
    printf( "%d\n", *cip2 );
    
    cip = &num;  //It can point to different integer that is not constant.
    cip2 = &num;
    printf( "%d\n", *cip );
    printf( "%d\n", *cip2 );
   
    return 0;
}
