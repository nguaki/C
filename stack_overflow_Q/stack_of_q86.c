#include <stdint.h>

uint16_t   u16c;
int32_t    s32;

int main()
{

    u16c = 100U;
    s32  = 10u - u16c;
    
    printf("%d\n", s32);

    s32  = (uint16_t)10 - u16c;
    printf("%d\n", s32);
    
    
}