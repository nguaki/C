//initialize.c
#include <iostream> 
#include <stdio.h>
#include "bowling.h"

extern FRAME Frames[12];

extern int iTotalScore;
extern int iScorePerFrame[12];
extern int iScorePerFrameCnt;

extern BOOLEAN bSpare;
extern BOOLEAN bStrike;

void
vInitialize()
{
    int i;
    
    iTotalScore = 0;
    for( i = 1; i<=10; i++ ){
        Frames[i].iThrow1 = 0;
        Frames[i].iThrow2 = 0;
        iScorePerFrame[i] = 0;
    }    
    iScorePerFrameCnt = 1;
    bSpare  = FALSE;
    bStrike = FALSE;
}