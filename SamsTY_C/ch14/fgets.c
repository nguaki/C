// Feb 14, 2017
//
// Demonstration of fgets().
//
//
/*
Enter a text:1234567890123456789012345
123456789
string size = 9
49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 
-----------------------------------------------
012345678
string size = 9
48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 
-----------------------------------------------
9012345
                   <=== Note the extra new line character.
string size = 8    <=== Why is this size 8?(Newline character is read. It occupies a space.)
57 | 48 | 49 | 50 | 51 | 52 | 53 | 10 | <=== ASCII numerical value 
//                                       10 probably represents a new line character.
-----------------------------------------------
Apr 26, 18   Note that unread characters are left in the buffer.
             Until these characters are read, they are left in the buffer.
             while(1) loop continues until all characters are read.
             Need to understand how OS works with stdin.
*/
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char buffer[10];
    int  i;
    
    printf( "Enter a text:" );
    while(1){
    
        fgets( buffer, 10, stdin );
    
        if ( buffer[0] == '\n' ) break;
        
        puts( buffer );
        printf( "string size = %d\n", (int)strlen(buffer));
        
        //Prints numerical ASCII value delimited by a pipe.
        for( i = 0; i<strlen(buffer); i++ )
            printf( "%d | ", buffer[i] );
            
        printf( "\n-----------------------------------------------\n" );
            
    }
    
    return 1;
}