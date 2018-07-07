//From my memory.
//Making sure I am comfortable with the syntax.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int
main( int argc, char **argv )
{
    FILE *f1;
    char caLine[MAX];
    unsigned short usLineNum = 1;
    
    if (( f1 = fopen( argv[1], "r" ) ) == NULL ){
        fprintf( stderr, "Cannot open a file to read.\n" );
        exit(2);
    }
    
    while( fgets( caLine, MAX, f1 ) != NULL ){
        printf( "%4d\t%s", usLineNum++, caLine ); // Note there is no need for a new line character.
    }
    
    return 1;
}