////////////////////////////////////////////////////////////
// Feb 14, 17
//
// Input and output in one statement.
//
//
//OUTPUT
//Enter a text:
//afdafasfsadf
//afdafasfsadf
//
// Apr 27, 2018    Replaced gets() with fgets().
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char buffer[100];
    
    puts("Enter a text:");
    //puts(gets(buffer));   // <=== input and output in one statement.
    puts(fgets(buffer, 100, stdin));   // <=== input and output in one statement.

    return 0;
}