/*
  Feb 16, 2017

  OUTPUT
  ------
  actual content of multi = 0x601060 location of multi = 0x601060
  actual content of multi[0] = 0x601060 location of multi[0] = 0x601060 
  actual content of multi[0][0] = 0x64 location of multi[0][0] = 0x601060
  multi[0][0] = 100
  *multi[0]   = 100
  **multi     = 100

  April 28, 2018
  Conceptually it is easy to understand.
  However, if looking at the memory address and how pointer works, I don't get it.
  
  multi, multi[0], multi[0][0] all located at same place. The location is 0x601060.
  
  I don't understand how multi really works internally.
  multi's value is 0x601060 and it located at memory location of 0x601060. What?
  So it is pointing to itself!!! Wouldn't this cause infinite loop?

*/
#include <stdio.h>

int multi[3][5];

int
main(void)
{
    multi[0][0] = 100;

    printf( "actual content of multi = %p location of multi = %p\n", multi, &multi );
    printf( "actual content of multi[0] = %p location of multi[0] = %p\n", multi[0], &multi[0] );
    printf( "actual content of multi[0][0] = %p location of multi[0][0] = %p\n", multi[0][0], &multi[0][0] );

    printf( "multi[0][0] = %d\n", multi[0][0] );
    printf( "*multi[0]   = %d\n", *multi[0] );
    printf( "**multi     = %d\n", **multi ); 
   
    
    
    return 0;
}