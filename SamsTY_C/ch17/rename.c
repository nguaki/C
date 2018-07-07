// Feb 17, 2017
//
// Demonstration of rename().
//
/*
Enter an old filename:temp.txt
Enter an new filename:temp2.txt
Successfully renamed temp.txt file.
dguai:~/workspace/SamsTY_C/ch17 $ ./a.out
Enter an old filename:temp2.txt
Enter an new filename:temp.txt
Successfully renamed temp2.txt file.

*/
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char oldfileName[80], newfileName[80];
    
    printf("Enter an old filename:");
    scanf("%s", oldfileName);
    printf("Enter an new filename:");
    scanf("%s", newfileName);
    
    if( rename(oldfileName,newfileName) == 0 )
        printf("Successfully renamed %s file.\n", oldfileName );
    else
        fprintf( stderr, "renamed failed for %s file.\n", oldfileName );

    return 0;
}