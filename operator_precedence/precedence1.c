///////////////////////////////////////////////////////////////////////////////////////
// Apr 25, 18    Generated output.
//
//OUTPUT
//x = 10
//x = 40
//y = 4
//z = 4
//x= 1
//
// May 3, 18     Added more outputs and comments.
//               The key to understanding this is identifying *= itself is an operation
//               which is different from * operation.
///////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int
main(void)
{
    int x = 2, y,z;

    //Method 1
    // x *= 2 + 3 expands to x = x * (2 + 3);
    // x = x * 5 which is x = 2 * 5 = 10.
    // Note that this does not become x = x * 2 + 3 which becomes 7.
    //Method 2
    // + operation has precedence over *= operation.
    // So it becomes x *= 5
    // Expand this to x = x * 5;
    // Note that * has precedence over +.
    // However *= itself is considered a single operation.
    // In this case, + has precedence over *=.
    x *= 2 + 3;  
    
    printf( "x = %d\n", x ); //Should print 10.
    
    //The assignment operator '=' has higher precedence over
    //"*=" operator.
    // x *= y = z = 4 is reduced to
    // x *= 4 which is further reduced to
    // x = x * 4 which is reduced to x = 40;
    x *= y = z = 4;
    printf( "x = %d\n", x );
    printf( "y = %d\n", y );
    printf( "z = %d\n", z );
   
    // '==' operator has higher precedence than '='
    // since y == z is true, x = 1;
    x = y == z; 
    printf( "x= %d\n", x ); //Should print 1.
    
    
    return 0;
}