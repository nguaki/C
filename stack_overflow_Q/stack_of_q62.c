/*dguai:~/workspace/C $ ./a.out
abc
[0]97  --> a
[1]98  --> b
[2]99  --> c
[3]10  -->         this is a newline character.
*/
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char caInput[30];
    
    fgets( caInput, sizeof caInput, stdin );
    
    for( size_t i = 0; i < strlen(caInput); i ++ )
        printf( "[%d]%d  --> %c\n", i, caInput[i], caInput[i] );
        
    return 0;
}