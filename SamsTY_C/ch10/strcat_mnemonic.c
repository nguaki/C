// Apr 26, 18   Uses fgets() instead of gets.
//              Removes a newline character for each string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pcConcatStr;

char *
pcWhichIsLonger( char *pcStr1, char *pcStr2 )
{
    if(strlen(pcStr1) > strlen(pcStr2))
        return pcStr1;
    return pcStr2;
}

char *
pcConcatStrings( char *pcStr1, char *pcStr2 )
{
    if( pcStr1[strlen(pcStr1)] == '\n' ) pcStr1[strlen(pcStr1)] = '\0';
    if( pcStr1[strlen(pcStr2)] == '\n' ) pcStr1[strlen(pcStr2)] = '\0';
    pcConcatStr = malloc( strlen(pcStr1) + strlen(pcStr2));

    strcpy( pcConcatStr, pcStr1 );
    strcat( pcConcatStr, pcStr2 );
    
    return pcConcatStr;
}


int
main( int argc, char *argv[])
{
    //char *pcStr1 = "abcde";
    //char *pcStr2 = "xyz";
    int i;
    
    char pcStr1[50], pcStr2[50];
    
    fgets( pcStr1, 50, stdin );
    fgets( pcStr2, 50, stdin );
    printf("strlen = %d\n", (int)strlen(pcStr1));
    
    //Remove a new line character. Input has a newline character.
    for(i=0; i<= strlen(pcStr1); i++)
    {
        if( pcStr1[i] == '\n')
        {
            pcStr1[i] = '\0';
            printf("Found a newline char at %d th character.\n", i);
        }
    }
    for(i=0; i<= strlen(pcStr2); i++)
    {
        if( pcStr2[i] == '\n')
        {
            pcStr2[i] = '\0';
            printf("Found a newline char at %d th character.\n", i);
        }
    }
    
    printf( "%s is longer of the two.\n", pcWhichIsLonger( pcStr1, pcStr2 ));
    printf( "%s is concatenated string.\n", pcConcatStrings( pcStr1, pcStr2 ));
    
    return 1;
}