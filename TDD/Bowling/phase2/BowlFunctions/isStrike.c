#include <iostream> 
#include <stdio.h>
#include "bowling.h"

extern FRAME Frames[12];



BOOLEAN
sIsStrike( int i )
{
    return( Frames[i].iThrow1 == 10 ? TRUE : FALSE );
}