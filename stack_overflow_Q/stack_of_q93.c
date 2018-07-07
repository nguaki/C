#include <stdio.h>

//#define MAX(one,two) ( if(one > two){return one;} else{return two;} )
#define MAX(one,two) ( one > two ? one:two )

int main(void)
{
 int a = 9;
 int b = 99;

 printf(" %d ", MAX(a,b));

 return 0;
}