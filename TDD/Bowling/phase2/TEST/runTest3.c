//runTest3.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);

void
vTest3()
{
    int i, iResult;
 
    vInitialize();

    vSetScore(1, 8, 2 );

    vSetScore(2, 7, 3 );

    vSetScore(3, 3, 4 );

    vSetScore(4, 10, 0 );

    vSetScore(5, 2, 8 );

    vSetScore(6, 10, 0 );

    vSetScore(7, 10, 0 );

    vSetScore(8, 8, 0 );

    vSetScore(9, 10, 0 );

    vSetScore(10, 8, 2 );

    vSetScore( 11, 9, 0 );

    iResult = iGetTotalScore();
    assert( iResult == 170 );
      
}

int
main( int argc, char *argv[])
{
    vTest3();
    std::cout << "passed test3\n";

    return 0;
}