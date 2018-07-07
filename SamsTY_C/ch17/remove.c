// Feb 17, 17
//
// Demonstration of remove().
//
/*
Enter a filename:direct.txt
Successfully removed direct.txt file.
*/
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    char fileName[80];
    
    printf("Enter a filename:");
    scanf("%s", fileName);
    
    if( remove(fileName) == 0 )
        printf("Successfully removed %s file.\n", fileName );
    else
        fprintf( stderr, "removed failed for %s file.\n", fileName );

    return 0;
}