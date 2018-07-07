// Jan 25, 17
//
// Demonstrates the memory efficiency of UNION over struct.
//
//OUTPUT:
//size of union structure = 4
//
//spain  Pineapple  3.40 liter
//USA    OJ         20 
//england  apple    3.40 pounds

#include <stdio.h>


typedef enum{
    PINTS, POUNDS, COUNT
}unit;

typedef union{
    int count;
    float volume;
    float weight;
}measure;

typedef struct{
    const char *country;
    const char *fruit_name;
    measure m;
    unit    u;
}fruit;

void
display( fruit X )
{
    switch(X.u)
    {
        case PINTS:
            printf( "%s  %s  %2.2f liter\n", X.country, X.fruit_name, X.m.volume );
            break;
        case POUNDS:
            printf( "%s  %s  %2.2f pounds\n", X.country, X.fruit_name, X.m.weight );
            break;
        default:
            printf( "%s  %s  %i \n", X.country, X.fruit_name, X.m.count );
            break;
    }
    
}

int
main()
{
    fruit pineapple = { "spain", "Pineapple", .m.volume = 3.4, PINTS };  //.m is a union assignment.
    fruit oj = { "USA", "OJ", {20}, COUNT};  //Assigns to first union element.
    fruit apple = { "england", "apple", .m.weight = 3.4, POUNDS };
    printf( "size of union structure = %d\n", (int)sizeof(measure) );
    display(pineapple);
    display(oj);
    display(apple);
    
    return 0;
}