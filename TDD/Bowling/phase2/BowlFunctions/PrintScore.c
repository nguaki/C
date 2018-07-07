//PrintScore.c
#include <iostream> 
#include <stdio.h>
#include "bowling.h"

extern BOOLEAN sIsStrike( int  );
extern BOOLEAN sIsSpare( int  );

extern FRAME Frames[12];

extern int iTotalScore;
extern int iScorePerFrame[12];
extern int iScorePerFrameCnt;


void
vPrintScore( int iScore )
{
    int i;
    
    printf( "Total score is %d\n", iScore );

    printf("---------------------------------------------------------------\n");
    printf("|");
    for( i=1; i<=10; i++ ){
        if( sIsStrike(i) )
            printf( "  X|");
        else if( sIsSpare(i ))
            printf( "%d \\|", Frames[i].iThrow1 );
        else
            printf( "%d %d|", Frames[i].iThrow1, Frames[i].iThrow2 );
    }
    printf("%d %d|", Frames[11].iThrow1, Frames[11].iThrow2);
    
    printf( "\n" );
    printf("-------------------------------------------------\n");

    printf("|");
    for( i = 1; i <= 10; i ++ ){
        if(iScorePerFrame[i] != 0 ){
            if( iScorePerFrame[i] < 10)
                printf( "  %d|", iScorePerFrame[i]);
            else if( iScorePerFrame[i] < 100)
                printf( " %d|", iScorePerFrame[i]);
            else
                printf( "%d|", iScorePerFrame[i]);
        }
    }
    printf( "\n" );
    printf("--------------------------------------------------\n");

}