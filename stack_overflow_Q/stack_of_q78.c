/*
Causes compilation error:

stack_of_q78.c:17:20: note: in expansion of macro ‘K’
    convpar cp = { .K = K};
                    ^
stack_of_q78.c:2:11: warning: excess elements in struct initializer [enabled by default]
 #define K 7

*/
#include <stdio.h>
#define K 7
typedef struct convpar_ {
  int K;
}convpar;


 
void func1(convpar cp)
{
  printf("cp.K = %d\n", cp.K);
}

int 
main(void)
{
   convpar cp = { .K = K};
  
  func1(cp);

  return 0;
}