/*
Feb 16, 17

Demonstration of pointer to function.

Enter a num: 1
one
Enter a num: 2
two
Enter a num: 3
default
Enter a num: 0
zero
Enter a num: 999
default
*/

#include <stdio.h>
void
zero()
{
    printf( "zero\n" );
}

void
one()
{
    printf( "one\n" );
}

void
two()
{
    printf( "two\n" );
}

void
default1()
{
    printf( "default\n" );
}



void
call_func( int i )
{
    void (*p_f)(); //function pointer that returns void.
    
    switch( i )
    {
        case 0:
            p_f = zero;
            break;
        case 1:
            p_f = one;
            break;
        case 2:
            p_f = two;
            break;
        default:
            p_f = default1;
            break;
    }
    
    p_f();
}


int
main(void)
{
    int i;
    
    while( i != 999 )
    {
        printf( "Enter a num: ");
        scanf( "%d", &i );
        call_func( i );
    }
    
    return 0;
}