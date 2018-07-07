//o
//o
#include <stdio.h>

int
main(void)
{
    char *a[] = { "Magic", "Kobe", "Kareem" };
    
    printf( "%c\n", a[1][1] );
    printf( "%c\n",  *(*(a+1)+1) );
    
    return 0;
}