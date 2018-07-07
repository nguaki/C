//  Feb 11, 17
//
//  Lesson 5 Ex 11
//  Demonstration of recursive.
//
//  pow(3,5) = 3 * 3 * 3 * 3 * 3
//
//  pow(3,5) = 3 * pow(3,4)
//  pow(3,4) = 3 * pow(3,3)
//  pow(3,3) = 3 * pow(3,2)
//  pow(3,2) = 3 * pow(3,1)
//  pow(3,1) = 3 * pow(3,0)
//  pow(3,0) = 1
//
/* 
OUTPUT
dguai:~/workspace/SamsTY_C/ch5 $ ./a.out
Enter a number to represent power: 4
81
dguai:~/workspace/SamsTY_C/ch5 $ ./a.out
Enter a number to represent power: 5
243
*/

#include <stdio.h>
#include <math.h>

unsigned int getPowOf3( unsigned int n );

int
main()
{
    int n;
    
    printf( "Enter a number to represent power: ");
    scanf( "%d", &n );
    
    printf( "%u\n", getPowOf3( n ) );
    
    return 0;
}



unsigned int
getPowOf3( unsigned int n )
{
    if ( n == 0 )
        return 1;
    else
        return 3 * getPowOf3(n-1);
}