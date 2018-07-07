/////////////////////////////////////////////////////////////////////////////
// April 5, 17
//
// OUTPUT:
// 7 2
//
// DESCRIPTION:
//   Initially
//     [ 7 ]    [ 8 ]
//      i         j
//     100       200    <==mem address
//
//   func( p=100, q=200 ) <== This is how memory address is sent.
//   p = 200              <== p now is assigned to memory address 200.
//   *p = 2               <== The new value at memory address is now 2.
//                            The variable 'i' holds that memory address.
//                            Therefore, i is assigned to 2.
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int i, j;

void
func( int *p, int *q )
{
    p = q;
    *p = 2;
}

int
main(void)
{
    i = 7;
    j = 8;
    
    func(&i, &j);
    
    printf( "%d %d\n", i, j );
    
    return 0;
}