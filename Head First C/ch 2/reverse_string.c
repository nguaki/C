/////////////////////////////////////////////////////////
//Jan 23, 17
//
//Prints a string in a reverse.
//
//Enter a string:abcdefghijklmnopqrstuvwxyz
//zyxwvutsrqponmlkjihgfedcba
/////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>


void print_reverse( char *input )
{
    int length = strlen(input);
    
    char *end;
    
    end = input + length - 1;  //Pointer arithmetic. Points at the end of the string before \0.
    
    //Checking the memory address is greater.
    while( end >= input )
    {
        printf( "%c", *end );
        end--;  //Pointer arithmetic. Decrements memory address.
    }
}

int
main()
{
    char caInput[80];
    
    printf( "Enter a string:" );
    scanf( "%79s", caInput );
    
    print_reverse( caInput );
    
    return 0;
}
    
        