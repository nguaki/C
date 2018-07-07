// This is a method of returning a pointer to char.
// It returns a literal string.
//
// Negative
//     Only works with a string.
//
// OUTPUT
//      This is a literal string.
#include <stdio.h>
#include <string.h>


char *
return_literal_string()
{
    return "This is a literal string.";
}

int
main(void)
{
    char *cp;
    
    cp = return_literal_string();
    
    printf( "cp = %s\n", cp );
    
    return 0;
}