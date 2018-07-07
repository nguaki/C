/*
 Mar 29, 2017
 
 Description:
    Explains how local variable ADDRESS cannot be returned.
    The primary reason is that the local variables are stored in stack memory
    location and stack memory gets deleted when a local function is done with
    its execution.
    
 When compiling with gcc, it returns with following messages:
 
return_local_addresss.c: In function ‘return_local_address’:
return_local_addresss.c:9:5: warning: function returns address of local variable [-Wreturn-local-addr]
     return x;
     ^
return_local_addresss.c: In function ‘main’:
return_local_addresss.c:17:8: error: incompatible types when assigning to type ‘char[11]’ from type ‘char *’
     ca = return_local_address();
*/

#include <stdio.h>


char *
return_local_address()
{
    char x[10] = "Hello";
    
    return x;    // <=== It is returning address of a character array.
                 //      Once this function is done with its execution,
                 //      the stack memory gets deleted thus the contents
                 //      of this local variable no longer exists.
}

int
main(void)
{
    char ca[11];
    
    ca = return_local_address();    //<== Cannot assign a pointer to char to a char array variable.
                                    //    The variable has to be a pointer to char in order to do this.
    
    printf("ca = %s\n", ca );
    
    return 0;
}