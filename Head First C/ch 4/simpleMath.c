//simpleMath.c
//
//Demonstration of a makefile.
//
#include <stdio.h>
#include "simpleMath.h"

int
main()
{

    char  cInput;
    float fResult;
    int   iNum1, iNum2;
    
    while(1){
    
        printf( "(a)Add (s)Subtract (m)Multiply (d)Divide:" );
        scanf( " %c", &cInput ); //Its important to put a space.  This will cause not to skip.
                
        if( cInput == 'x') break;

        printf( "Enter 2 numbers:" );
        scanf( "%i %i", &iNum1, &iNum2 );

        switch( cInput )
        {
            case 'a':
                fResult = fAdd( iNum1, iNum2 );
                break;
            case 's':
                fResult = fSub( iNum1, iNum2 );
                break;
            case 'm':
                fResult = fMul( iNum1, iNum2 );
                break;
            case 'd':
                fResult = fDiv( iNum1, iNum2 );
                break;
            default:
                break;
        }
    

        printf( "Answer = %f\n", fResult );
    };
    return 0;
}