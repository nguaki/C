//Compilation warining:
//warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
//     pi = (int * )n;
//Run error
//   Segmentation fault
#include <stdio.h>

int
main(void)
{
    int n = 0;
    int *pi;
    
    pi = (int * )n;
    
    printf( "%d\n", *pi );
    
    return 0;
}