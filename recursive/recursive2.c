//OUTPUT:
// 8
//
//
// Aprl 26, 18    Added Pictoral diagram.
/****
          main()
          func(5,0xAA)     Assume memory address of x is 0xAA.
          |------------------------------------------
              n=5
              5<=1?N
              t = func(4,0xAA)=5 <--------
              f = 5+3=8 [5]0xAA          |
              return 8                   |
              |--------------------------|---------------------
                n=4                      |
                4<=1?N                   |
            --> t = func(3,0xAA)=3       |
            |   f = 3+2=5  [3]0xAA       | 
            |   return 5            -----| 
            |    |-----------------------------------------------
            |      n=3
            |      3<=1? N
            |      t = func(2,0xAA)=2 <--------
            |      f = 2 + 1 =3  [2]0xAA      |
            ----- return 3                    | 
                  |---------------------------|--------------------
                    n=2                       |
                    2<=1? N                   |
            |---->  t= func(1,0xAA) = 1       | 
            |       f = 1 + 1 =2  [1]0xAA     |
            |       return 2 -----------------|
            |        |----------------------------------------------
            |         n=1
            |         1<=1? Y
            |         *fp = 1        [1]0xAA
            --------  return 1  
*****/
#include <stdio.h>

int
func( int n, int *fp )
{
    int t;
    int f;
    
    if( n <= 1 ){
        *fp = 1;
        return 1;
    }
    
    t = func(n -1,fp);
    f = t + *fp;
    
    *fp = t;
    
    return f;
}

int
main(void)
{
    int x = 15;
    
    printf( "%d\n", func( 5, &x ) );


    return 0;
}