//ABCD
//
// Illustrates how numerical values of 0..128 change in behavior
// in the context of the type of variables it is stored.
// When stored into character 
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
   char ca[5];
   
   ca[0] = 65;
   ca[1] = 66;
   ca[2] = 67;
   ca[3] = 'Z';
   ca[4] = 0;
   
   printf( "%s\n", ca );


   return 0;
}