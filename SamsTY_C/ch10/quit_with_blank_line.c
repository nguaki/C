// Feb 11, 17
//
// Demonstrates how to look for just a blank line using gets() command.
//
/*
OUTPUT
dguai:~/workspace/SamsTY_C/ch10 $ ./a.out
afasfdsa
You entered = afasfdsa
werwer
You entered = werwer
gafa
You entered = gafa
dfhdh
You entered = dfhdh

Good bye
*/

#include <stdio.h>


int
main(void)
{
    char *ptr, buffer[250];
    
    while(  *(ptr = gets(buffer)) != '\0' ){  //The importance of dereferencing *.
        printf( "You entered = %s\n", buffer );
    }

    puts( "Good bye" );
    return 0;
}