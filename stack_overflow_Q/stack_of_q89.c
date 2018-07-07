#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char
EEPROM_Read( unsigned long long addr )
{
    printf("mem address = %llu\n", addr);
    //return (unsigned char*)addr;
    unsigned char *ucp;
    
    ucp = (unsigned char *)addr;
    return *ucp;
    //return *addr;
}

/*
float 
E2P_read_float(unsigned int addr){
    unsigned char i;
    unsigned char* temp;
    float result;
    temp = (unsigned char *)&result;
    for(i=0; i<4; ++i)
        *(temp+i) = EEPROM_Read(addr+i);
    return result;
}
*/

int
main(int argc, char **argv )
{

    float f = 6.12345678;
    float f1 = 0.0;
    unsigned char ca[4];
    unsigned long long ullMemAddress;
    
    ullMemAddress = (unsigned long long)&f;
    printf( "%x\n", *(unsigned int*)&f);
    ca[0] = EEPROM_Read( ullMemAddress++ );
    printf( "ca[0]=%x\n", ca[0]);
    ca[1] = EEPROM_Read( ullMemAddress++ );
    printf( "ca[1]=%x\n", ca[1]);
    ca[2] = EEPROM_Read( ullMemAddress++ );
    printf( "ca[2]=%x\n", ca[2]);
    ca[3] = EEPROM_Read( ullMemAddress++ );
    printf( "ca[3]=%x\n", ca[3]);
     
    memcpy(&f1, ca, 4 );
    printf("%lf\n", f1);
}