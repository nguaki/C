//Feb 18, 17
//
//Demonstration of strcspn()
//
/**
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdefghihjk
Enter a string:hjkl
First occurrence is at 7
dguai:~/workspace/SamsTY_C/ch18 $ ./a.out
Enter a string:abcdefgh
Enter a string:ijkl
Doesn't exists!
**/
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
    
    location = strcspn(str1, str2);
    
    if (location == strlen(str1) )
        printf( "Doesn't exists!\n" );
    else
        printf( "First occurrence is at %d\n", location );
        
    return 0;
    
}