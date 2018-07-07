//10
//100
#include <stdio.h>

int
main(void)
{
     int num = 10;

     int *const cip = &num;    //Must declare and initialize at the same time.
                               //   1. Cannot marry to different integer.
     
     int x;
     

     printf( "%d\n", *cip );
     *cip = 100;               //Can modify using cip.
     printf( "%d\n", *cip );  
     
     //cip = &x;              //But cannot change to different address.
     
     return 0;
}