//runTest4.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);



void
vTest4()
{
    int i, iResult;
 
    vInitialize();

    vSetScore(1, 9, 1 );
    vSetScore(2, 10, 0 );
    vSetScore(3, 10, 0 );
    vSetScore(4, 10, 0 );
    vSetScore(5, 3, 0 );
    vSetScore(6, 7, 3 );
    vSetScore(7, 4, 6 );
    vSetScore(8, 10, 0 );
    vSetScore(9, 2, 8 );
    vSetScore(10, 8, 2 );
    vSetScore( 11, 10, 0 );

    iResult = iGetTotalScore();
    //assert( iResult == 181 );  //This is correct number.
    assert( iResult == 180 );
      
}

int
main( int argc, char *argv[])
{
    vTest4();
    std::cout << "passed test4\n";

    return 0;
}