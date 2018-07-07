//Jan 28, 17
//
//Demonstration of variadic function.
//
//
//Total = 13.50
//Total = 17.80
//Total = 71.20


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef enum ITEMS{ BEEF_JERKY, BUBBLE_GUM, BASEBALL_CARDS, COKE }ITEMS;
float price[] = { 4.5, 2.3, 5.0, 1.5 };

float
fCalTotal( int args, ... )
{
    float fTotal = 0.0;
    int i;
    
    va_list ap;
    va_start( ap, args );
    
    for( i = 0; i<args; i++ )
        fTotal = fTotal + price[va_arg(ap, ITEMS)];
    
    
    va_end( ap );

    return fTotal;
}


int
main()
{

    printf( "Total = %2.2f\n", fCalTotal(3, BEEF_JERKY, BEEF_JERKY, BEEF_JERKY ));
    printf( "Total = %2.2f\n", fCalTotal(5, BEEF_JERKY, BEEF_JERKY, BASEBALL_CARDS, BUBBLE_GUM, COKE ));
    printf( "Total = %2.2f\n", fCalTotal(20, BEEF_JERKY, BEEF_JERKY, BASEBALL_CARDS, BUBBLE_GUM, COKE, 
        BEEF_JERKY, BEEF_JERKY, BASEBALL_CARDS, BUBBLE_GUM, COKE, 
        BEEF_JERKY, BEEF_JERKY, BASEBALL_CARDS, BUBBLE_GUM, COKE,
        BEEF_JERKY, BEEF_JERKY, BASEBALL_CARDS, BUBBLE_GUM, COKE ));


    return 0;
}