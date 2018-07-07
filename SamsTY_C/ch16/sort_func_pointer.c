/* Feb 16, 17

Demonstration of function pointer.

eee
rrr
ttt
www
iii
ppp
qq
aaa
bbb

eee
rrr
ttt
www
iii
ppp
qq
aaa
bbb

After descending sort 
www
ttt
rrr
qq
ppp
iii
eee
bbb
aaa

After ascending sort 
aaa
bbb
eee
iii
ppp
qq
rrr
ttt
www
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void sort( char *lines[], int N, int );
int  getInputs( char *lines[] );
int ascending( char *, char *);
int descending( char *, char *);

int
main(void)
{
    char *lines[MAX];
    int  i, iNumOfLines;
    
    iNumOfLines = getInputs( lines );
    
    if( iNumOfLines < 0 ){
        printf( "Error with inputs.");
        return 1;
    }
    
    for( i=0; i<iNumOfLines; i++ )
        printf( "%s\n", lines[i] );
        
    sort( lines, iNumOfLines, 0 );

    printf( "After ascending sort \n");
    for( i=0; i<iNumOfLines; i++ )
        printf( "%s\n", lines[i] );
    
    sort( lines, iNumOfLines, 1 );

    printf( "After descending sort \n");
    for( i=0; i<iNumOfLines; i++ )
        printf( "%s\n", lines[i] );

    for( i=0; i<iNumOfLines; i++ )
        if( lines[i] != NULL ) free(lines[i]);

    return 0;
}

//Returns positive if p2 is greater than p1.
int
ascending( char *p1, char *p2 )
{
    return( strcmp(p2, p1) );   //Returns p2-p1
}

//Returns positive if p1 is greater than p2.
int
descending( char *p1, char *p2 )
{
    return( strcmp(p1, p2) );
}

void
sort( char *lines[], int N, int sortOrder )
{
    int a, b;
    char *temp;
    
    int (* compare)(char *, char *);
    
    //Function pointer gets a new function.
    compare = sortOrder ? ascending : descending; 
    
    for( a=1; a<N; a++)
        for( b=0; b<N-1; b++)
        {
            if( compare(lines[b], lines[b+1]) > 0 )
            {
                temp       = lines[b];                  
                lines[b]   = lines[b+1];
                lines[b+1] = temp;
            }
        }
}


////////////////////////////////////////////////////////
// Apr 28, 18   Rewrote string entry.
////////////////////////////////////////////////////////
int
getInputs( char *lines[] )
{
    int n = 0;
    char buffer[80];

    //while( n<MAX &&  (gets(buffer) != 0) && (buffer[0] != '\0') ){
    while( n<MAX ){
        
        printf("Enter a string:");
        if( fgets(buffer,80,stdin ) == NULL ) break;
        if( buffer[0] == '\n') break;
        
        if( ( lines[n] = (char *)malloc(strlen(buffer)+1) ) == NULL )
                return -1;
        buffer[strlen(buffer)-1] = '\0'; //Remove newline character.
        strcpy(lines[n], buffer );
        n++;
    }
    
    return n;
    
}