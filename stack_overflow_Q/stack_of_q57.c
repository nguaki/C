//Running without header files.
//libc has all binary executables.
//
//OUTPUT: hell

//#include <stdio.h>
//#include <string.h>

extern void * malloc(size_t);
extern void free(void *);
extern void * strcpy(char *, const char *);
extern char * printf( const char *, const char *);
int
main(void)
{
   char *cp;
   
   cp = malloc(5);
   strcpy( cp, "hell");
   printf("%s\n", cp);
   free(cp);
   return 0;
}