//runTest_Angela.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);

void
vTest_Angela()
{
    int i, iResult;
 
    vInitialize();

    vSetScore(1, 10, 0 );
    vSetScore(2, 8, 2 );
    vSetScore(3, 8, 2 );
    vSetScore(4, 10, 0 );
    vSetScore(5, 9, 1 );
    vSetScore(6, 8, 2 );
    vSetScore(7, 10, 0 );
    vSetScore(8, 9, 1 );
    vSetScore(9, 10, 0 );
    vSetScore(10, 8, 2 );
    vSetScore( 11, 9, 0 );

    iResult = iGetTotalScore();
    assert( iResult == 195 );
      
}

int
main( int argc, char *argv[])
{
    vTest_Angela();
    std::cout << "passed test_Angela\n";

    return 0;
}