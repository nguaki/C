/////////////////////////////////////////////////////////////////
//Jan 20, 17
//
// Demonstratin of pointer arithmetic.
//
//OUTPUT:
//
//call me.
//call me.
//call me.
//call me.
//0x40073c  <== memory location at 0th index.
//0x400742  <== memory location at 6th index
//
//Each character takes up 1 byte.
// |--------------------------------------------|
// |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|<== array index
// |d|o|n|'|t| |c|a|l|l|  |m |e |
// |---------------------------------------------|
// |c|d|e|f|0|1|2     <== Hexadecimal memory representation.
// |---------------------------------------------|
//
//
//4
//4
//0x7ffceaac2870  <== Memory location of ipNum[0]
//0x7ffceaac2878  <== Memory location of ipNum[2]
//0x7ffceaac2878  
//Each integer takes up 4 bytes.
//
//  |---------------------------------------------|
//  |0      |1      |2      |3      |   <== array index
//  |----------------------------------------------
//  |1      |2      |4
//  |---------------------------------------------
//  |0|1|2|3|4|5|6|7|8          <== memory location 
/////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

void
vPrintMsg( char *msg )
{

    puts( msg + 6 );
    puts( &msg[6] );
    printf( "%s\n", msg + 6 );  //Pointer arithmetic.  Since this is a character array, each addition is 1
                                //since character takes up 1 byte.
    printf( "%s\n", &msg[6] );
    
    printf( "%p\n", msg );
    printf( "%p\n", msg + 6);
}

void
vPrintNum( int *ipNum )
{
    printf( "%i\n", ipNum[2] );
    printf( "%i\n", *(ipNum + 2) );//Pointer arithmetic.  Since this is a character array, each addition is 4
                                   //since integer takes up 4 bytes.
    
    printf( "%p\n", &ipNum[0] );
    printf( "%p\n", &ipNum[2] );
    printf( "%p\n", ( ipNum + 2 ) );
    
}
int
main()
{
    char *msg = "Don't call me.";
    int  iArray[] = { 1, 2, 4 };
    
    vPrintMsg(msg);
    vPrintNum( iArray );

}