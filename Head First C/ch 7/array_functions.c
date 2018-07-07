// Jan 28, 17
//
// Creates an array of function names.
// Calls functions from this array.
//
//
/*
XYZ would like to dump.
ABC would like to have second_chance.
DEF would like to propose marriage.
FFF would like to pursue law suit.
*/
#include <stdio.h>
#include <stdlib.h>

enum STATUS  { DUMP, SECOND_CHANCE, MARRIAGE, LAW_SUIT };

typedef struct{
    char *name;
    enum STATUS status;
}CLIENT;

CLIENT clients[] = { {"XYZ", DUMP}, {"ABC", SECOND_CHANCE}, {"DEF", MARRIAGE}, {"FFF", LAW_SUIT} };


void
dump( CLIENT client )
{
    printf( "%s would like to dump.\n", client.name );
}

void
second_chance( CLIENT client )
{
    printf( "%s would like to have second_chance.\n", client.name );
}
void
marriage( CLIENT client )
{
    printf( "%s would like to propose marriage.\n", client.name );
}
void
law_suit( CLIENT client )
{
    printf( "%s would like to pursue law suit.\n", client.name );
}
void (*clientAcknowledge[])(CLIENT) = { dump, second_chance, marriage, law_suit };//Function array

int
main()
{
    int i;
    
    for( i = 0; i < 4; i++ )
        (clientAcknowledge[clients[i].status])(clients[i]);//Calling function directly.
    return 0;
}



