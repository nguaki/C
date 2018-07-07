//Apr 28, 18
//start time: 10:19
//end   time: 10:52   
//duration  : 33 minutes
//Problem: Sort was incorrect.
//         Stupid mistake: used return(b-a) instead of return(strcmp(b-a)).
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define ASCENDING 1
#define DESCENDING 0

int
iGetLines( char *cpLines[] )
{
    int iCnt = 0;
    char caBuffer[80];
    
    while( iCnt < MAX )
    {
        if (fgets( caBuffer, 80, stdin ) == NULL ) break;
        if(caBuffer[0] == '\n') break;
        caBuffer[strlen(caBuffer)-1] = '\0';
        
        if( ( cpLines[iCnt] = malloc(strlen(caBuffer)+1) ) == NULL ) break;

        strcpy(cpLines[iCnt],caBuffer);
    
        iCnt++;
    }
    return iCnt;
}

int
iAscending( char *a, char *b )
{
    return( strcmp(b,a) );
}

int
iDescending( char *a, char *b )
{
    return( strcmp(a,b) );
}

 void
 vSort( char *cpLines[], int iCnt, short SortOrder  )
 {
     int (*compare)(char *, char *);
     int a,b;
     char *cpTemp;
     
     compare = ( SortOrder == ASCENDING ) ? iAscending : iDescending;

      for( a=1; a<iCnt; a++ )
        for( b=0; b<iCnt-1; b++ )
        {
          if( compare( cpLines[b], cpLines[b+1]) > 0)
          {
              cpTemp = cpLines[b];
              cpLines[b] = cpLines[b+1];
              cpLines[b+1] = cpTemp;
          }
        }
     
 }

int
main(void)
{
    char *cpLines[MAX];
    int  iNumLines;
    int  i;
    
    
    iNumLines = iGetLines(cpLines);
    
    for( i=0; i<iNumLines;i++ ) printf( "%s\n", cpLines[i]);
    
    vSort( cpLines, iNumLines, DESCENDING );
    printf( "After sort\n" );
    for( i=0; i<iNumLines;i++ ) printf( "%s\n", cpLines[i]);
    
    vSort( cpLines, iNumLines, ASCENDING );
    printf( "After sort\n" );
    for( i=0; i<iNumLines;i++ ) printf( "%s\n", cpLines[i]);
   
    return 0;
}