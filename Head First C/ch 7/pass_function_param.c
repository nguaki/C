//Jan 28, 17
//
//Demonstration of passing function name as a parameter.
//
/****
daniel: christian, faithful, educated, disciplined
david: christian, faithful, educated, artist, warrior
=========================
david: christian, faithful, educated, artist, warrior
=========================
jesus: christian, sinless
****/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *characters[] = {
    "daniel: christian, faithful, educated, disciplined",
    "joseph: christian, faithful, disciplined",
    "david: christian, faithful, educated, artist, warrior",
    "jesus: christian, sinless"
};

int
find_christian_educated( char *des )
{
    return ( strstr(des, "christian") && strstr(des, "educated"));
}

int
find_christian_sinless( char *des )
{
    return ( strstr(des, "christian") && strstr(des, "sinless"));
}

int
find_christian_warrior( char *des )
{
    return ( strstr(des, "christian") && strstr(des, "warrior"));
}

//fnc is a functional pointer .
void
find( int(*fnc )(char *) )
{
    int i;
    
    for( i = 0; i < 4; i++ ){
        //Calls a function.
        if( fnc( characters[i]) )
            printf( "%s\n", characters[i] );
    }
}

int
main()
{

    find(find_christian_educated);
    printf( "=========================\n" );
    find(find_christian_warrior);
    printf( "=========================\n" );
    find(find_christian_sinless);

    return 0;
}