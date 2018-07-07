//0x7ffd7dbecd04
//0x7ffd7dbecd05  <== Increments just 1 byte
#include <stdio.h>

int
main(void)
{
  int i;
  void *vp;
  
  vp = &i;
  printf( "%p\n", vp );
  vp++;
   printf( "%p\n", vp );
  
  return 0;
 }
  