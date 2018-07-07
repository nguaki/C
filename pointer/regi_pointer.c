// April 4, 17
//
// regi_pointer.c
//
// DESCRIPTION:
// Cannot store address of a register variable in C.
//
//
//
#include <stdio.h>

int
main(void)
{
    register int x;
    register int *p;
    int y;
    
    p = &y; // <== This is fine. 
    p = &x;  //This line causes compilation error:
             // dguai:~/workspace/C $ gcc regi_pointer.c
             // regi_pointer.c: In function ‘main’:
             // regi_pointer.c:11:5: error: address of register variable ‘x’ requested
             // p = &x;

    
    return 0;
}
    