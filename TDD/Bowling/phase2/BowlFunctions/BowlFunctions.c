// BowlFunctions.c
#include <iostream> 
#include <stdio.h>
#include "bowling.h"

using namespace std;

int iTotalScore;
int iScorePerFrame[12];
int iScorePerFrameCnt;

FRAME Frames[12];

BOOLEAN bSpare;
BOOLEAN bStrike;

extern BOOLEAN sIsSpare( int );
extern BOOLEAN sIsStrike( int );

int 
iGetTotalScore()
{
    int i;
    iTotalScore = 0;
    for( i = 1; i <= 10; i++ ){
        
        if( sIsStrike(i) ){
                if( i == 10 ){
                    iTotalScore = iTotalScore + 10 + Frames[11].iThrow1 + Frames[11].iThrow2;

                }else if( i <= 9 ){
                    
                    //This is case for consecutive strikes.
                    //e.g. if 8th turn is a strike, 9th is skipped.
                    //     if 10th turn is a strike, 11th is skipped
                    //     Get score of 12th turn.
                    if( sIsStrike( i+1 ) )
                        iTotalScore = iTotalScore + 10 + Frames[i+1].iThrow1 + Frames[i+2].iThrow1;
                    else
                        iTotalScore = iTotalScore + 10 + Frames[i+1].iThrow1 + Frames[i+1].iThrow2;
                }
                bStrike = TRUE; 
                
            }
        else if( sIsSpare(i) ){
            if( i == 10 ){
                  iTotalScore = iTotalScore + 10 + Frames[11].iThrow1;
                  //iTotalScore = iTotalScore + ithScore[i+2];                  //i = 21;   //The calculation is done.
            }else if( i <= 9 ){
                  iTotalScore = iTotalScore + 10 + Frames[i+1].iThrow1;
            }
            bSpare = TRUE;
        }
        else{
            iTotalScore += Frames[i].iThrow1 + Frames[i].iThrow2;
            bSpare = FALSE;
            bStrike = FALSE;
        }
        //cout << iTotalScore << endl;

    }
    //cout << iTotalScore << endl;
    return iTotalScore;
}