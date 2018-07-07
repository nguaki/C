#include <stdio.h>

int
main(void)
{
    unsigned char c, c254, c255, c256;
    char sc127, sc128 , sc129, scn127, scn128, scn129;
    
    c = -1;
    c254 = 254;
    c255 = 255;
    c256 = 256;
    
    printf( "%c   %d\n",  65, 65);
    
    printf( "c254 = %d c255 = %d  c256 = %d\n", c254, c255, c256);
    
    sc127 = 127;
    sc128 = 128;
    sc129 = 129;
    scn127 = -127;
    scn128 = -128;
    scn129 = -129;
    
    printf( "scn129 = %d scn128 = %d scn127 = %d sc127 = %d  sc128 = %d sc129 = %d\n", scn129, scn128, scn127, sc127, sc128, sc129);
    
    return 0;
}