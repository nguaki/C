/////////////////////////////////////////////////////////////////////
// April 1, 2017
// 
// const_declaration.c
//
// OUTPUT:
//  memory address of globalConstInt = 0x400628
//  memory address of localConstInt = 0x7ffe3cfd300c
//  memory address of constInt = 0x4006a8
//
// EXPLANATION:
//  Explains how the location of 'const' declaration matters.
//
//////////////////////////////////////////////////////////////////////
#include <stdio.h>

const int globalConstInt = 100;

void
modifyVariable()
{
      const int localConstInt = 50;  // <=== Although this has 'const' qualifier,
                                     // the variable is still is stored in stack memory space
                                     // which is not read only.  Once this procedure
                                     // is done executing, this variable is lost.
                                     
      static const int constInt = 100; // This variable will not get lost.
      
      printf("memory address of localConstInt = %p\n", &localConstInt );
      printf("memory address of constInt = %p\n", &constInt );
    //localConstInt = 200;

    
    
}
int
main(void)
{
    
    printf("memory address of globalConstInt = %p\n", &globalConstInt );

    //globalConstInt = 200;
    
    modifyVariable();
    
    return 0;
}