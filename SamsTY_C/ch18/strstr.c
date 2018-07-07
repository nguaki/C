//Feb 17, 17
//
//Demonstration of strstr().
//
/*
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdeffg
Enter a string:ff
First occurrence is at 5
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdefgh
Enter a string:kkk
Doesn't exists!
*/
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char str1[50], garbage[50], str2[10], *s1;
    int  location;
    
    
    printf("Enter a string:");
    scanf("%s", str1 );
    
    fgets( garbage, 50, stdin );
    
    printf("Enter a string:");
    scanf("%s", str2);
    
    fgets( garbage, 50, stdin );
    
    s1 = strstr(str1, str2);
    
    if (s1 == NULL )
        printf( "Doesn't exists!\n" );
    else
        printf( "First occurrence is at %ld\n", s1 - str1 );
        
    return 0;
    
}