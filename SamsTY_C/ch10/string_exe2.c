// April 26, 18
// OUTPUT
// string1 = Second
#include <stdio.h>

int
main(void)
{
    char *string1;
    char *string2 = "Second";
    char string3[10];
    char string4[] = "Four";
    
    string1 = string2;
    
    printf( "string1 = %s\n", string1 );
    
    //string3 = string4;  //<== Compilation error. This makes a logical sense
                        //that this should work.  However, it doesn't.
                        //Reason is that string3[10] is considered as a type
                        //char[10].  Here is the error message.
                        //string_exe2.c:15:13: error: incompatible types when assigning to type ‘char[10]’ from 
                        //type ‘char * string3 = string4;
                        //The compiler is recognizing string4 as char *.
                        //But not string3.

    return 0;
}