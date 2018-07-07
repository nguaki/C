#include <stdio.h>
#include <cassert>
#include "bowling.h"

extern BOOLEAN sIsSpare( int );
extern BOOLEAN sIsStrike( int );
extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);

extern int  iTotalScore;
extern BOOLEAN bSpare;
extern BOOLEAN bStrike;
extern int iScorePerFrame[12];
extern int iScorePerFrameCnt;
extern void vPrintScore(int);

int
main( int argc, char *argv[] )
{ 
    int iFrame, iScore1, iScore2;
    vInitialize();
    
    //sConsStrikeCnt = 0;
    for(iFrame = 1 ; iFrame <= 11; iFrame++)
    { 
        printf( "Enter Frame # %d Throw 1 Score:", iFrame );
        scanf("%d", &iScore1);
        if( sIsSpare(iFrame - 1) ){
            vSetScore( iFrame, iScore1, 0 );
            if( iFrame <= 10 )
            {
                //printf( "Total score is %d\n", iGetTotalScore() - iScore1 );
                iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore() - iScore1;
                vPrintScore(iGetTotalScore() - iScore1 );
            }
            else
            {
                //printf( "Total score is %d\n", iGetTotalScore() );
                iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore();
                vPrintScore(iGetTotalScore());
                break;
            }
        }
        
        if( iScore1 == 10 && iFrame <= 10 ){
            bStrike = TRUE;
            vSetScore( iFrame, 10, 0 );
            printf( "Please wait for next 2 throws for the score ... \n" );
            if( sIsStrike(iFrame - 1) && sIsStrike(iFrame -2)){
                //printf( "Total score is %d\n", iGetTotalScore() - 30);
                iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore() - 30;
                vPrintScore(iGetTotalScore() - 30);

            }
            continue;
        }

        printf( "Enter Frame # %d Throw 2 Score:", iFrame );
        scanf("%d", &iScore2);
        vSetScore( iFrame, iScore1, iScore2 );
        
        if( sIsStrike(iFrame - 1) ){
            if( iFrame <= 10 )
            {
                //printf( "Total score is %d\n", iGetTotalScore() - iScore1 - iScore2 );
                iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore() - iScore1 - iScore2;
                vPrintScore(iGetTotalScore() - iScore1 - iScore2);
            }
            else
            {
                //printf( "Total score is %d\n", iGetTotalScore() );
                iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore();
                vPrintScore(iGetTotalScore());
                break;
            }
        }

        
        if( sIsSpare(iFrame) )
            printf( "Please wait for next throw for the score ... \n" );
        else
        {
           // printf( "Total score is %d\n", iGetTotalScore() );
            iScorePerFrame[iScorePerFrameCnt++] = iGetTotalScore();
            vPrintScore(iGetTotalScore());
        }
        
        if( iFrame == 10 && ( iScore1 + iScore2 < 10 ) ) break;
    }

    return 0;
}