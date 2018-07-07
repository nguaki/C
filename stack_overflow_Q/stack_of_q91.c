#include <stdio.h>

typedef void fcn_t(void);
typedef void (*ptr_t)(void);

fcn_t f;
fcn_t *pf;
ptr_t pf2;

void
f(void)
{
    printf("I am void\n");
}

void 
vSayHi(void)
{
    printf( "Hi\n" );
}

int
main(void)
{

   pf2 = vSayHi;
   pf2();
   
   pf = vSayHi;
   pf();
    
   f();
   return 0;
}