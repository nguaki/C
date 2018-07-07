/////////////////////////////////////////////////
// Jan 23, 17
//
// Demonstrates the difference between char *xyz and char xyz[]
// variable declaration.
//
// This code tries to modify values of a variable which
// is a char pointer.
// This will cause a segmentation fault since the program is
// trying to modify a value which is stored in the constant 
// section of the memory.
//
/////////////////////////////////////////////////

#include <stdio.h>
int
main()
{
    //This assignment makes this string to be read only.
    //This string is kept in "Constant" portion of the
    //memory.
    //This is same as "const char *cards = "JQK"; 
    char *cards = "JQK";   
                           
    //In order to modify the value, the variable should
    //be an array.  By doing this, the value is kept
    //in stack side of the memory which is Read and write.
    //char cards[] = "JQK";   
    
    char a_card = cards[2];
    
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    
    puts( cards );

    return 0;
} 