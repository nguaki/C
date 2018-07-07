// Feb 11, 17
//
//Demonstrates the usage of gets() command.
//Apparently, it is deprecated.
/*
OUTPUT
dguai:~/workspace/SamsTY_C/ch10 $ gcc gets.c 
gets.c: In function ‘main’:
gets.c:9:5: warning: ‘gets’ is deprecated (declared at /usr/include/stdio.h:638) [-Wdeprecated-declarations]
     gets(input);
     ^
/tmp/ccaIn9yo.o: In function `main':
gets.c:(.text+0x29): warning: the `gets' function is dangerous and should not be used.
dguai:~/workspace/SamsTY_C/ch10 $ ./a.out
Enter a text:
ajfdlajflk
You have entered ajfdlajflk.

Apr 26,18   Entered usage with fgets().
*/
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char input[100];
    
    puts("Enter a text:");
    
    //Note that gets() do not store a new line character.
    //It adds a NULL character at the end in order to make
    //it a string.
    gets(input);
    
    //fgets( input, 100, 0 );    Causes seg fault.   0 representation of stdin doesn't work.
    //fgets( input, 100, STDIN );    //Capital is not recognized
    fgets( input, 100, stdin );   
    printf( "You have entered %s.\n", input );
    
    return 0;
}
