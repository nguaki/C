//runTest1.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);

void
vTest1()
{
    int i, iResult;
 
    vInitialize();

    vSetScore(1, 5, 2 );

    vSetScore(2, 3, 5 );

    vSetScore(3, 5, 0 );

    vSetScore(4, 4, 1 );

    vSetScore(5, 9, 1 );

    vSetScore(6, 5, 1 );

    vSetScore(7, 7, 1 );

    vSetScore(8, 10, 0 );

    vSetScore(9, 5, 2 );

    vSetScore(10, 10, 0 );

    vSetScore(11, 10, 2 );

    iResult = iGetTotalScore();
    
    assert( iResult == 100 );
      
}

int
main( int argc, char *argv[])
{
    vTest1();
    std::cout << "passed test1\n";

    return 0;
}