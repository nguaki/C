///////////////////////////////////////////////////////
//Jan 23, 17
//
//Usage of strstr().
//
/*
OUTPUT
dguai:~/workspace/Head First C/ch 2 $ ./a.out
Enter a search string:Bill
found in track # 1.
dguai:~/workspace/Head First C/ch 2 $ ./a.out
Enter a search string:moo
found in track # 3.
*/
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

char track[][80] = { "Beat it, Beat it",
    "Billi Jean is not my love",
    "See yourself in the mirror",
    "Smooth Criminal",
    "I just can't stop falling in love with you"
    };
    
void
search_track( char *search_string )
{
    int i;
    
    for( i = 0; i<5; i ++ ){
        if( strstr( track[i], search_string ) )
            printf( "found in track # %i.\n", i );
    }
}

int
main()
{
    char search_string[80];
    
    printf("Enter a search string:");
    scanf( "%79s", search_string );
    
    //search_string[strlen(search_string)-1] = '\0';
    
    search_track( search_string );
    
    return 0;
}