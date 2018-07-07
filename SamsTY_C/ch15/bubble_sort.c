/*
Feb 16, 17

 Demonstration of array to pointer to char.

ttt
eee
hhh
uuu
ooo
qqq

ttt
eee
hhh
uuu
ooo
qqq

After sort 
eee
hhh
ooo
qqq
ttt
uuu

Apr 28, 18   Frees up memory.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void sort( char *lines[], int N );
int  getInputs( char *lines[] );

int
main(void)
{
    char *lines[MAX];
    int  i, iNumOfLines;
    
    iNumOfLines = getInputs( lines );
    
    if( iNumOfLines < 0 ){
        printf( "Error with inputs.")
        return 1;
    }
    for( i=0; i<iNumOfLines; i++ )
        printf( "%s\n", lines[i] );
        
    sort( lines, iNumOfLines );

    printf( "After sort \n");
    for( i=0; i<iNumOfLines; i++ )
        printf( "%s\n", lines[i] );
    
    //free allocated memory.
    for( i=0; i<iNumOfLines; i++)
        if( lines[i] != NULL ) free lines[i];
    
    return 0;
}

void
sort( char *lines[], int N )
{
    int a, b;
    char *temp;
    
    for( a=1; a<N; a++)
        for( b=0; b<N-1; b++)
        {
            if( strcmp(lines[b], lines[b+1]) > 0 )
            {
                temp       = lines[b];                  
                lines[b]   = lines[b+1];
                lines[b+1] = temp;
            }
        }
    
}


int
getInputs( char *lines[] ){
    
    int n = 0;
    char buffer[80];
    while( n<MAX &&  (gets(buffer) != 0) && (buffer[0] != '\0') ){
        
        if( ( lines[n] = (char *)malloc(strlen(buffer)+1) ) == NULL )
            return -1;
        strcpy(lines[n], buffer );
        n++;
    }
    
    return n;
    
}