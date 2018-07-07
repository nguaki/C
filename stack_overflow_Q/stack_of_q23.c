#include <stdio.h>

int
main(void)
{
 int x;

 int *var1;
 var1 = &x; 
 const int *var2 = var1;

    x = 3;
 
   *var2 = 30;  //stack_of_q23.c:16:4: error: assignment of read-only location ‘*var2’

   x =20;
   printf("x = %d", x);
   
   return 0; 
}