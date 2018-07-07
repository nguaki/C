//Feb 18, 17
//
//Demonstration of strcat()
/*
a
ab
abc
abcd
abcde
abcdef
abcdefg
abcdefgh
abcdefghi
abcdefghij
abcdefghijk
abcdefghijkl
abcdefghijklm
abcdefghijklmn
abcdefghijklmno
abcdefghijklmnop
abcdefghijklmnopq
abcdefghijklmnopqr
abcdefghijklmnopqrs
abcdefghijklmnopqrst
abcdefghijklmnopqrstu
abcdefghijklmnopqrstuv
abcdefghijklmnopqrstuvw
abcdefghijklmnopqrstuvwx
abcdefghijklmnopqrstuvwxy
abcdefghijklmnopqrstuvwxyz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
int
main(void)
{
    char str1[ALPHABET_SIZE+1]; //+1 is for NUL character.
    char str2[2];               
    int i;
    
    str2[1] = '\0';   //Make sure the last char is a string NUL char.
    
    str1[0] = '\0';  //<==str1 is just an empty string.

    for(i = 97; i<123; i++)  //97 is ASCII decimal value for 'A'.
    {
        str2[0] = i;  //Remember that last char is a string NUL char.
        
        strcat( str1, str2 );  //Adds NUL terminated string to end of str1.
                               //This will make str1 always NUL terminated.
        
        puts(str1);
    }
}