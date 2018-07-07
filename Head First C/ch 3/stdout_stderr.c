/***************************************************************
 Jan 23, 17
 
 Redirection on of stdin, stdout, stderr.
 STDIN is coming from "secret.txt".
 STDOUT is redirected to output1 file.
 STDERR is redirected to output2 file.
 
OUTPUT:
dguai:~/workspace/Head First C/ch 3 $ ./a.out < secret.txt > output1 2>output2
dguai:~/workspace/Head First C/ch 3 $ cat output1
BUY
SIX
EGGS
AND
SOME
MILK
dguai:~/workspace/Head First C/ch 3 $ cat output2
THE
SUBMARINE
WILL
SURFACE
AT
NINE
PM
********************************************************************/
#include <stdio.h>
#include <string.h>

int
main()
{
    char word[10];
    int i = 0;
    
    while( scanf("%9s", word) == 1 ){
        if( i%2 )
            fprintf( stdout, "%s\n", word );
        else
            fprintf( stderr, "%s\n", word );
        i++;
    }
    
    return 0;
}