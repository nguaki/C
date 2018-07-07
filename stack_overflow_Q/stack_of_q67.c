#include <stdio.h>
#include <string.h>

int
main(void)
{
   //char *s = "This is a wild and exciting life!";  <===causes seg fault
   char s[] = "This is a wild and exciting life!";
   
   for (char *p = strtok(s," "); p != NULL; p = strtok(NULL, " "))
   {
     fputs(p,stdout);
     fprintf( stdout, "\n" );
   }
   
   return 0;
}