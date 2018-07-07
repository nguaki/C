#include <iostream>
#include <cassert>

extern void vInitialize(void);
extern void vSetScore( int, int );
extern int  iGetTotalScore(void);

void
vTestGutter()
{
    int i, iResult;
    
    vInitialize();
    for( i = 0; i < 20; i ++ ){
        vSetScore( i, 0 );
    }
    
    iResult = iGetTotalScore();
    
    assert( iResult == 0 );
    
}
void
vTestSpare()
{
    int i, iResult;
    
    vInitialize();
    
    vSetScore( 0, 5 );
    vSetScore( 1, 5 );
    vSetScore( 2, 4 );
    
    for( i = 3; i <= 19; i++ ){
        vSetScore( i, 0 );
    }
    
    iResult = iGetTotalScore();
    
    assert( iResult == 18 );
    
}
void
vTestStrike()
{
     int i, iResult;
    
    vInitialize();
    
    vSetScore( 0, 5 );
    vSetScore( 1, 4 );
    vSetScore( 2, 4 );
    vSetScore( 3, 4 );
    vSetScore( 4, 10 );
    vSetScore( 6, 4 );
    vSetScore( 7, 5 );
    for( i = 8; i <= 19; i++ ){
        vSetScore( i, 0 );
    }
    
    iResult = iGetTotalScore();
    assert( iResult == 45  );
}

void
vTestRegFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 0; i <= 17; i++ ){
        vSetScore( i, 0 );
    }
    
    vSetScore( 18, 5 );
    vSetScore( 19, 4 );

    iResult = iGetTotalScore();
    assert( iResult == 9  );
   
}
void
vTestSpareFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 0; i <= 17; i++ ){
        vSetScore( i, 0 );
    }
    
    vSetScore( 18, 5 );
    vSetScore( 19, 5 );
    vSetScore( 20, 9 );
    iResult = iGetTotalScore();
    assert( iResult == 19  );
   
}

void
vTestStrikeFinish()
{
    int i, iResult;
    
    vInitialize();

    for( i = 0; i <= 17; i++ ){
        vSetScore( i, 0 );
    }
    
    vSetScore( 18, 10 );
    vSetScore( 19, 0 );
    vSetScore( 20, 9 );
    vSetScore( 21, 9 );
    iResult = iGetTotalScore();
    assert( iResult == 28  );
   
}

void
vTestPerfectScore()
{
    int i, iResult;
    
    vInitialize();

    vSetScore( 0, 10 );
    vSetScore( 1, 0 );
    vSetScore( 2, 10 );
    vSetScore( 3, 0 );
    vSetScore( 4, 10 );
    vSetScore( 5, 0 );
    vSetScore( 6, 10 );
    vSetScore( 7, 0 );
    vSetScore( 8, 10 );
    vSetScore( 9, 0 );
    vSetScore( 10, 10 );
    vSetScore( 11, 0 );
    vSetScore( 12, 10 );
    vSetScore( 13, 0 );
    vSetScore( 14, 10 );
    vSetScore( 15, 0 );
    vSetScore( 16, 10 );
    vSetScore( 17, 0 );
    vSetScore( 18, 10 );
    vSetScore( 19, 0 );
    vSetScore( 20, 10 );
    vSetScore( 21, 10 );

    
    iResult = iGetTotalScore();
    assert( iResult == 300 );
}
void
vTestAllSpares()
{
    int i, iResult;
    
    vInitialize();

    vSetScore( 0, 5 );
    vSetScore( 1, 5 );
    vSetScore( 2, 5 );
    vSetScore( 3, 5 );
    vSetScore( 4, 5 );
    vSetScore( 5, 5 );
    vSetScore( 6, 5 );
    vSetScore( 7, 5 );
    vSetScore( 8, 5 );
    vSetScore( 9, 5 );
    vSetScore( 10, 5 );
    vSetScore( 11, 5 );
    vSetScore( 12, 5 );
    vSetScore( 13, 5 );
    vSetScore( 14, 5 );
    vSetScore( 15, 5 );
    vSetScore( 16, 5 );
    vSetScore( 17, 5 );
    vSetScore( 18, 5 );
    vSetScore( 19, 5 );
    vSetScore( 20, 10 );

    
    iResult = iGetTotalScore();
    assert( iResult == 155 );
}

void
vTest1()
{
    int i, iResult;
 
    vInitialize();

    vSetScore( 0, 5 );
    vSetScore( 1, 2 );
    vSetScore( 2, 3 );
    vSetScore( 3, 5 );
    vSetScore( 4, 5 );
    vSetScore( 5, 0 );
    vSetScore( 6, 4 );
    vSetScore( 7, 1 );
    vSetScore( 8, 9 );
    vSetScore( 9, 1 );
    vSetScore( 10, 5 );
    vSetScore( 11, 1 );
    vSetScore( 12, 7 );
    vSetScore( 13, 1 );
    vSetScore( 14, 10 );
    vSetScore( 15, 0 );
    vSetScore( 16, 5 );
    vSetScore( 17, 2 );
    vSetScore( 18, 10 );
    vSetScore( 19, 0 );
    vSetScore( 20, 10 );
    vSetScore( 21, 2 );

    
    iResult = iGetTotalScore();
    assert( iResult == 100 );
      
}
void
vTest2()
{
    int i, iResult;
 
    vInitialize();

    vSetScore( 0, 8 );
    vSetScore( 1, 2 );
    vSetScore( 2, 10 );
    vSetScore( 3, 0 );
    vSetScore( 4, 7 );
    vSetScore( 5, 0 );
    vSetScore( 6, 6 );
    vSetScore( 7, 4 );
    vSetScore( 8, 9 );
    vSetScore( 9, 1 );
    vSetScore( 10, 10 );
    vSetScore( 11, 0 );
    vSetScore( 12, 8);
    vSetScore( 13, 2 );
    vSetScore( 14, 2 );
    vSetScore( 15, 8 );
    vSetScore( 16, 10 );
    vSetScore( 17, 0);
    vSetScore( 18, 9 );
    vSetScore( 19, 1 );
    vSetScore( 20, 10 );

    iResult = iGetTotalScore();
    assert( iResult == 175 );
      
}
void
vTest3()
{
    int i, iResult;
 
    vInitialize();

    vSetScore( 0, 8 );
    vSetScore( 1, 2 );
    vSetScore( 2, 7 );
    vSetScore( 3, 3 );
    vSetScore( 4, 3 );
    vSetScore( 5, 4 );
    vSetScore( 6, 10 );
    vSetScore( 7, 0 );
    vSetScore( 8, 2 );
    vSetScore( 9, 8 );
    vSetScore( 10, 10 );
    vSetScore( 11, 0 );
    vSetScore( 12, 10);
    vSetScore( 13, 0 );
    vSetScore( 14, 8 );
    vSetScore( 15, 0 );
    vSetScore( 16, 10 );
    vSetScore( 17, 0);
    vSetScore( 18, 8 );
    vSetScore( 19, 2 );
    vSetScore( 20, 9 );

    iResult = iGetTotalScore();
    assert( iResult == 170 );
      
}
void
vTest4()
{
    int i, iResult;
 
    vInitialize();

    vSetScore( 0, 9 );
    vSetScore( 1, 1 );
    vSetScore( 2, 10 );
    vSetScore( 3, 0 );
    vSetScore( 4, 10 );
    vSetScore( 5, 0 );
    vSetScore( 6, 10 );
    vSetScore( 7, 0 );
    vSetScore( 8, 3 );
    vSetScore( 9, 0 );
    vSetScore( 10, 7 );
    vSetScore( 11, 3 );
    vSetScore( 12, 4);
    vSetScore( 13, 6 );
    vSetScore( 14, 10 );
    vSetScore( 15, 0 );
    vSetScore( 16, 2 );
    vSetScore( 17, 8 );
    vSetScore( 18, 8 );
    vSetScore( 19, 2 );
    vSetScore( 20, 10 );

    iResult = iGetTotalScore();
    assert( iResult == 181 );
      
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

    vTest1();
    std::cout << "passed test1\n";
    vTest2();
    std::cout << "passed test2\n";
    vTest3();
    std::cout << "passed test3\n";
    vTest4();
    std::cout << "passed test4\n";
    return 0;
}
