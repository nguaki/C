#include <iostream>

using namespace std;

static int iTotalScore;
static int ithScore[23];
static short bSpare;
static short bStrike;

void
vInitialize()
{
    int i;
    
    iTotalScore = 0;
    for( i = 0; i < 23; i++ )
        ithScore[i] = 0;
    bSpare = 0;
    bStrike = 0;
}

void
vSetScore( int iTurn, int iScore )
{
    ithScore[iTurn]   =  iScore;
}

short
sIsSpare( int i )
{
    return( ithScore[i] + ithScore[i+1] == 10 ? 1 : 0 );
    
}

short
sIsStrike( int i )
{
    return( ithScore[i] == 10 ? 1 : 0 );
}

int 
iGetTotalScore()
{
    int i;
    
    for( i = 0; i <= 21; i++ ){
        
        if( i % 2 == 0 )
        {
            if( sIsStrike(i) ){
                //Last round. (18th and 19th bowl.)
                if( i == 18 ){
                    //If 18th is strike. 19th bowl is zero.
                    //The bowler is entitled to 20th and 21st bowl.
                    iTotalScore = iTotalScore + 10 + ithScore[i+2] + ithScore[i+3];
                    i = 21;
                   
                }else if( i <= 16 ){
                    
                    //This is case for consecutive strikes.
                    //e.g. if 8th turn is a strike, 9th is skipped.
                    //     if 10th turn is a strike, 11th is skipped
                    //     Get score of 12th turn.
                    if( sIsStrike( i+ 2 ) )
                        iTotalScore = iTotalScore + 10 + ithScore[i+2] + ithScore[i+4];
                    else
                        iTotalScore = iTotalScore + 10 + ithScore[i+2] + ithScore[i+3];
                }
                bStrike = 1; 
                
            }
            else if( sIsSpare(i) ){
                if( i == 18 ){
                  iTotalScore = iTotalScore + 10 + ithScore[i+2];
                  //iTotalScore = iTotalScore + ithScore[i+2];
                  i = 21;   //The calculation is done.
                }else if( i < 18 ){
                  iTotalScore = iTotalScore + 10 + ithScore[i+2];
                }
                bSpare = 1;
            }
            else{
                iTotalScore += ithScore[i];
                bSpare = 0;
                bStrike = 0;
            }
        }
            
        else{
            if( !bSpare && !bStrike ) iTotalScore += ithScore[i];
        }
        //cout << iTotalScore << endl;

    }
    //cout << iTotalScore << endl;
    return iTotalScore;
}