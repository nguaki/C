// Returns a literal string.
//
// Negative
//     Uses global variable.
// OUTPUT
//     This is global.

#include <stdio.h>
#include <string.h>

char global_char[20];

char *
return_global_string()
{
    strncpy( global_char, "This is global", 10 );
    
    return global_char;
}

int
main(void)
{
    char *cp;
    
    cp = return_global_string();
    
    printf( "cp = %s\n", cp );
    
    return 0;
}