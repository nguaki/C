//A method to return a character array.
//In this case, it uses static variable.
//
//Negative: The value of the variable can be overwritten.
//
//OUTPUT:
//cp = hello malloc

#include <stdio.h>
#include <string.h>


char *
return_static_ptr()
{
    static char xyz[20];
    
    strncpy( xyz, "Hello static", 20 );
    
    return xyz;
}

int
main(void)
{
    char *cp;
    
    cp = return_static_ptr();
    
    printf( "cp = %s\n", cp );
    
    return 0;
}