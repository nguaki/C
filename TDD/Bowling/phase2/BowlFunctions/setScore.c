//setScore.c
#include <iostream> 
#include <stdio.h>
#include "bowling.h"

extern FRAME Frames[12];


void
vSetScore( int iFrameNum, int iThrow1Score, int iThrow2Score )
{
    Frames[iFrameNum].iThrow1 = iThrow1Score;
    Frames[iFrameNum].iThrow2 = iThrow2Score;
}