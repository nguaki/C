//address = 0x400604 c = Hello there
//address = 0x400604 cc = Hello there
#include <stdio.h>
#include <string.h>

int
main(void)
{
   char *c = "Hello there";
   char *cc = "Hello there";
   

   printf("address = %p c = %s\n", c, c);
   printf("address = %p cc = %s\n", cc, cc);
   

   return 0;

}