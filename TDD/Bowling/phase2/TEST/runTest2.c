//runTest2.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);


void
vTest2()
{
    int i, iResult;
 
    vInitialize();

    vSetScore(1, 8, 2 );

    vSetScore(2, 10, 0 );

    vSetScore(3, 7, 0 );

    vSetScore(4, 6, 4 );

    vSetScore(5, 9, 1 );

    vSetScore(6, 10, 0 );

    vSetScore(7, 8, 2 );

    vSetScore(8, 2, 8 );

    vSetScore(9, 10, 0 );

    vSetScore(10, 9, 1 );

    vSetScore( 11, 10,0 );

    iResult = iGetTotalScore();
    assert( iResult == 175 );
      
}

int
main( int argc, char *argv[])
{
    vTest2();
    std::cout << "passed test2\n";

    return 0;
}