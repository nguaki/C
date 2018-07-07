#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
   char *cp = "string";
   char *cp1 = NULL;
   
   cp1 = strdup(cp);
   
   printf("%s\n", cp1);
   
   free(cp1);
   
   return 0;
}
   