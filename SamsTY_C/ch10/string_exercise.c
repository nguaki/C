// Feb 11, 17
//
// Interesting string exercise.
//
//OUTPUT
//A
//73
#include <stdio.h>


int
main(void)
{
    char *string = "A new language";
    
    printf( "%c\n", *string ); //Prints out 'A'.
                               //string variable is an array of characters.
                               //string itself represents the memory address of
                               //the beginning of the string.
                               //Dereferening string by *string gets the first
                               //character.
                             
    printf( "%d\n", *string + 8 ); //Prints out 73.
                                   //*string has ASCII value of 65.
                                   //Add 8 to it makes 73.
    return 0;
}