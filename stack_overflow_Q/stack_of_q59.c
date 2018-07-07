#include <stdio.h>

int
main(void)
{
  //initailize array elements
    char ZeroA[6]   = {0xC0,0x07,0x40,0x04,0xC0,0x07,};
    char OneA[6]    = {0x80, 0x04, 0xC0, 0x07, 0x00, 0x04,};
    char TwoA[6]    = {0x40, 0x07, 0x40, 0x05, 0xC0, 0x05,};
    char ThreeA[6]  = {0x40, 0x05, 0x40, 0x05, 0xC0, 0x07,};
    char FourA[6]   = {0x80, 0x03, 0x00, 0x02, 0x80, 0x07,};
    char FiveA[6]   = {0xC0, 0x05, 0x40, 0x05, 0x40, 0x07,};
    char SixA[6]    = {0xC0,0x05,0x40,0x05,0x40,0x07,}; 
    char SevenA[6]  = {0x40,0x04,0x40,0x03,0xC0,0x00,};
    char EightA[6]  = {0xC0,0x07,0x40,0x05,0xC0,0x07,};
    char NineA[6]   = {0xC0,0x05,0x40,0x05,0xC0,0x07,};
    char TenA[6]    = {0x00,0x01,0x80,0x03,0x00,0x01,};

char *mCount;     //address holder
char var = 6;    //Just random number for illustration

//char *XYZ[11]={&ZeroA,&OneA,&TwoA,&ThreeA,&FourA,&FiveA,&SixA,&SevenA,&EightA,&NineA,&TenA};
char *XYZ[11]={ZeroA,OneA,TwoA,ThreeA,FourA,FiveA,SixA,SevenA,EightA,NineA,TenA};

mCount = XYZ[var];   

  printf( "sizeof cp = %lu sizeof array = %lu \n", sizeof(mCount), sizeof(TenA) );
 
  printf( "address of an array = %p  address of first element = %p address of address of array = %p\n", TenA, &TenA[0], &TenA );
  int i = 0;
  if( TenA == &TenA[0] ) printf( "same same\n");
  for( i = 0; i < 6; i ++ )
    printf( "%c ", mCount[i] );
  return 0;
}