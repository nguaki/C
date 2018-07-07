#include <stdio.h>

int
main(void)
{
    int *pi;
    
    pi = 0;    // 0 here is sames as NULL which is #define NULL (void *)0
    
    pi = 100;  //Compilation error:
               //context_matters.c:10:8: warning: assignment makes pointer from integer without a cast [enabled by default]
               //pi = 100;

    
    return 0;
}