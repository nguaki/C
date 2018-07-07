///////////////////////////////////////////
// April 5. 17
//
//OUTPUT
//  7
//
//   main  f(1)
//   -------------------
//      
//      |-------------------
//       i=1
//       1>=5? N
//       n=1+1=2
//       return f(2)
//         |---------------------
//           n=2
//           2>=5? N
//           i=2
//           n=2+2=4
//           return f(4)
//           |-----------------------
//             n=4
//             4>=5?N
//             n=4+3=7
//             return f(7)
//             |----------------------------
//               n=7
//               7>=5?Y return 7
//    
//    From here, stacks get popped.
//
//    Apr 26, 18          Added diagram of recursion
////////////////////////////////////////////
#include <stdio.h>

int
f( int n )
{
    static int i = 0;
    
    if( n >= 5 ) return n;
    
    i++;
    
    n = n + i;
    
    return f(n);
    //f(n);
}

int
main(void)
{
    printf( "%d\n", f(1));
    
    return 0;
}
    