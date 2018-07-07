/////////////////////////////////////////////////////////////////
//Jan 23, 17
//
// Redirection of STDIN and STDOUT.
// Output of one executable becomes an input of another executable using pipe..
// STDIN : numbers.txt
// STDOUT : output.txt
// pipe : ( exe1 | exe2 )
//
// get2OddNums executable prints out 2 numbers only if both numbers are odd.
// 
//(./get2OddNums | ./addNums ) < numbers.txt > output.txt
//
/*
dguai:~/workspace/Head First C/ch 3 $ cat numbers.txt
2 3
5 5  <=== both numbers are odd
3 4
6 6
7 7  <=== both numbers are odd
dguai:~/workspace/Head First C/ch 3 $ cat output.txt
10
14
*/
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>


int
main()
{
    int i1, i2;
    
    while( scanf( "%i %i", &i1, &i2 ) == 2 ){
        if( ( i1 % 2 ) && ( i2 % 2 ) )
            printf( "%d %d\n", i1, i2 );
    }
    return 0;
}