#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
uint32_t x = 0;
x = x << 33;  // Blamo
x = x >> (-1);  // Kapow

return 0;
}