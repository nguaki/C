#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
   char *tabheader = "Sound";
   *tabheader = 'L';

   printf("%s\n", tabheader );

   return 0;
}
