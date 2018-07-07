#include <stdio.h>

int g_uArray[5] =
{ 1, 1, 2, 3, 5};

void* foo( int uIndex );

int main()
{
    int* uVar;
    uVar = (int *)foo( 2 );  //Both of these statements work!!!
    uVar = foo( 2 );
    printf( "Value = %u\n", *uVar );
    return 0;
}

void* foo( int uIndex )
{
    return (void*) &g_uArray[uIndex];
}