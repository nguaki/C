#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct abc{
    int x;
    char *pc;
}a;

void
assign( char *pc )
{
     a.pc = pc;
    
}
void
assign1( char pc[] )
{
     a.pc = pc;
     strcpy( a.pc, "xxx");
    
}
int
main(int argc, char *argv[])
{
    char *pc;
    char *pc1;
    char ca[10];
    
    strcpy(ca, "Hellothere");
    pc1 = argv[1];
    pc = strdup(argv[1]);
    a.pc = argv[1];
    
    printf( "%s\n", pc);
    printf( "%s\n", a.pc);
    
    assign(ca);
    printf( "%s\n", a.pc);
    
    strcpy( ca, "Hello Moon" );
    assign1(ca);
    printf( "%s\n", a.pc);

    return 0;
}