//p = 0x7ffc703fb0d0
//q = 0x7ffc703fb0d4
//p = 0x7ffc703fb0d0
//q = 0x7ffc703fb0d4
#include <stdio.h>

int
main(void)
{
    int ar[2];
    int *p = ar;
    int *q = p+1;

    printf("p = %p\n", (const void*)p);
    printf("q = %p\n", (const void*)q);
    
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    return 0;
}
