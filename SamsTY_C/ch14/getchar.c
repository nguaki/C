// Feb 14, 17
//
// Demonstration of getchar().  
// The input characters are echoed and buffered.
// 
//
/*
sdfsdfdsfsdfsdfsdf  <== characters are entered/echoed on the screen and gets buffered.
sdfsdfdsfsdfsdfsdf  <===once the 'Enter' is pushed, all the buffered charadters gets displayed on stdout.

*/
#include <stdio.h>

int
main(void)
{
    int c;
    
    while( ( c = getchar() ) != '\n' )   //<===Keep getting chars until 'carriage return'
        putchar(c);  //<=== the characters are not displayed immediately

    return 0;
}