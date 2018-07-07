//runTestOthers.c
#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int, int );
extern int  iGetTotalScore(void);


void
vTestGutter()
{
    int i, iResult;
    
    vInitialize();
    for( i = 1; i <= 10; i ++ ){
        vSetScore( i, 0, 0 );
    }
    
    iResult = iGetTotalScore();
    
    assert( iResult == 0 );
    
}

void
vTestSpare()
{
    int i, iResult;
    
    vInitialize();
    
    vSetScore( 1, 5, 5 );
    vSetScore( 2, 4, 0 );
    
    for( i = 3; i <= 10; i++ ){
        vSetScore( i, 0, 0 );
    }
    
    iResult = iGetTotalScore();
    
    assert( iResult == 18 );
    
}


void
vTestStrike()
{
     int i, iResult;
    
    vInitialize();
    
    vSetScore( 1, 5, 4);
    vSetScore( 2, 4, 4);
    vSetScore( 3, 10, 0);
    vSetScore( 4, 4, 5);
    
    for( i = 5; i <= 10; i++ ){
        vSetScore( i, 0, 0 );
    }
    
    iResult = iGetTotalScore();
    assert( iResult == 45  );
}
void
vTestRegFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 1; i <= 9; i++ ){
        vSetScore( i, 0, 0 );
    }
    
    vSetScore( 10, 5, 4 );

    iResult = iGetTotalScore();
    assert( iResult == 9  );
   
}


void
vTestSpareFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 1; i <= 9; i++ ){
        vSetScore( i, 0, 0 );
    }
    
    vSetScore( 10, 5, 5);
    vSetScore( 11, 9, 0);
    iResult = iGetTotalScore();
    assert( iResult == 19  );
   
}


void
vTestStrikeFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 1; i <= 9; i++ ){
        vSetScore( i, 0, 0 );
    }
    
    vSetScore(10, 10, 0);
    vSetScore(11, 9, 9);
    iResult = iGetTotalScore();
    assert( iResult == 28  );
}

void
vTestPerfectScore()
{
    int i, iResult;
    
    vInitialize();

    for( i = 1; i <= 10; i++ ){
        vSetScore( i, 10, 0 );
    }

    vSetScore(11, 10, 10);
    iResult = iGetTotalScore();
    assert( iResult == 300 );
}
void
vTestAllSpares()
{
    int i, iResult;
    
    vInitialize();

    for( i = 1; i <= 10; i++ ){
        vSetScore( i, 5, 5 );
    }

    vSetScore(11, 10, 0 );

    
    iResult = iGetTotalScore();
    assert( iResult == 155 );
}




int
main( int argc, char *argv[])
{

    vTestGutter();
    std::cout << "passed gutter test\n";
    
    vTestSpare();
    std::cout << "passed spare test\n";
    
    vTestStrike();
    std::cout << "passed strike test\n";
    vTestRegFinish();
    std::cout << "passed Finished without spare nor strike\n";
   
    vTestSpareFinish();
    std::cout << "passed Finished with spare\n";
     
    vTestStrikeFinish();
    std::cout << "passed Finished with strike\n";
    
    vTestPerfectScore();
    std::cout << "passed perfect score\n";
    
    vTestAllSpares();
    std::cout << "passed all spares\n";

    return 0;
}
