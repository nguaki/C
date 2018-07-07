// Feb 17, 17
//
// Pass function pointer to a function.
//
//
/*
Enter a num: 1
one
Enter a num: 2
two
Enter a num: 3
default
Enter a num: 4
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
call_func( void (*p_f)() )
{
    p_f();
}


int
main(void)
{
    int i;
    void (*p_f)();
    
    while( i != 999 )
    {
        printf( "Enter a num: ");
        scanf( "%d", &i );
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
        //call_func( p_f );
        p_f(); //Must have () to call a function.
        
    }
    
    return 0;
}