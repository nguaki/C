#include <stdio.h>


int
main()
{

    int num4, num3, sum3, a, b, c, d, e, f, g, h, sum;
    printf("enter two binary numbers\n");

    scanf("%d", &num3);
    scanf("%d", &num4);

    printf( "%d\n", num3);
    printf( "%d\n", num4);
    
    sum = num3 | num4;
    sum = 8|4;
    sum = 12 | 8;
    
    printf("sum = %d\n", sum);
    
    a = (sum / 10000000) % 10;
    b = (sum / 1000000) % 10;
    c = (sum / 100000) % 10;
    d = (sum / 10000) % 10;
    e = (sum / 1000) % 10;
    f = (sum / 100) % 10;
    g = (sum / 10) % 10;
    h = (sum / 1) % 10;
    sum3 = (a * 128) + (b * 64) + (c * 32) + (d * 16) + (e * 8) + (f * 4) + (g * 2) + (h);
    printf("the answer is %d\n", sum3);
    
    return 0;
}