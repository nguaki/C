//isSpare.c
#include <iostream> 
#include <stdio.h>
#include "bowling.h"

extern FRAME Frames[12];



BOOLEAN
sIsSpare( int i )
{
    return( (Frames[i].iThrow1 + Frames[i].iThrow2) == 10 &&  ( Frames[i].iThrow1 != 10 ) ? TRUE : FALSE );
    
}