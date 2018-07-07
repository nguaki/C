//Feb 11, 17
//
//Demonstration of recursion.
//
//
//  stack 1)5! = 5 * 4!
//  stack 2)4! = 4 * 3!
//  stack 3)3! = 3 * 2!
//  stack 4)2! = 2 * 1!
//  stack 5)1
//
//  returns 1 (pops stack 5)
//  returns 2 (pops stack 4)
//  returns 6 (pops stack 3)
//  return 24 (pops stack 2)
//  return 120(pops stack 1)
//
/*OUTPUT
Enter a number:5
Factorial of iNum is 120
dguai:~/workspace/SamsTY_C/ch5 $ ./a.out
Enter a number:6
Factorial of iNum is 720
*/
#include <stdio.h>
#include <stdlib.h>

long lGetFactorial(unsigned int);

int
main( int argc, char **argv )
{

    unsigned int iNum;
    
    printf("Enter a number:" );
    scanf( "%u", &iNum );
    
    printf( "Factorial of iNum is %ld\n", lGetFactorial(iNum) );
    
    return 0;
}

unsigned int
lGetFactorial( unsigned int N )
{

    //Base case.
    if( N == 1 )
        return 1;
    else
        return N * lGetFactorial( N - 1 );
}
