//March 30, 17
//This method wraps character array in a structure.
//
//Negative: It can waste memory space of character array.
//
//OUTPUT
//EXEC/method6
//a_wrap = Hello wrapper

#include <stdio.h>
#include <string.h>


struct wrapper{
    char ca[20];
};

struct wrapper
return_wrapper()
{
    struct wrapper a_wrap;
    
    strncpy( a_wrap.ca, "Hello wrapper", 15 );
   
    return a_wrap;
}

int
main(void)
{
    struct wrapper a_wrap;
    
    a_wrap = return_wrapper();
    
    printf( "a_wrap = %s\n", a_wrap.ca );
    
    return 0;
}