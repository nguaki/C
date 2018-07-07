// OUTPUT
// 3
// 1
// 4
// -1
//-5
//6
#define print( z ) printf( "%d\n", z );

#include <stdio.h>

int
main(void)
{
    int x = 2, y=0, z=0;
    
    z = x++ - 1;
    
    print( x );
    print( z );
    
    //z = 1
    //x = 3
    
    // z += (-3) + (1)       <== x is post+increment but y is pre-increment
    //                           binary '+' operation has precedence over '+=' operation.
    // z = 1 + (-3) + (1)
    // z = -1
    // z += -x++ + ++y;
    // z += -(x++) + (++y)   <== post increment has higher precedence than unary operator.(????)
    //                           I thought unary has higher precedence.
    // z += (-(x++)) + (++y) 
    // z += (-(3)) + 1
    // z += -2
    // z = 1 + (-2)
    // z = -1
    z += -x++ + ++y; // Remember that post increment takes place after 
    
    print(x);
    print(z);
    
    int p = 5;
    
    //Demonstration of unary operation has higher precedence over post increment.
    z = -p++;
    print(z);
    print(p);
    return 0;
}