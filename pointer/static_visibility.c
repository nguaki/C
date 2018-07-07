//x=100
#include <stdio.h>

int *
func1()
{
    static int x;
    
    x = 100;
    return &x;
}

void
func2(int *mem_add)
{
    printf( "x=%d\n", *mem_add);  //Compilation error
    //return &x;
}

int
main(void)
{
    int *mem_add = func1();
    func2(mem_add);

    return;
}