// Feb 18, 17
//
// Demonstration of strspn().
// Opposite of strcspn().
// This checks for occurrences of characters that are not from the second
// string.
/*
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdefghjkl
Enter a string:abcdef
First occurrence is at 6   <===g doesn't exists and it is located on 6th position.
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdefghj
Enter a string:kkk  <===none of the characters in str1 are present in str2.
First occurrence is at 0
*/
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char str1[50], garbage[50], str2[10];
    int  location;
    
    printf("Enter a string:");
    scanf("%s", str1 );
    
    fgets( garbage, 50, stdin );
    
    printf("Enter a string:");
    scanf("%s", str2);
    
    fgets( garbage, 50, stdin );
    
    location = strspn(str1, str2);
    
    if (location == strlen(str1) )
        printf( "Doesn't exists!\n" );
    else
        printf( "First occurrence is at %d\n", location );
        
    return 0;
    
}