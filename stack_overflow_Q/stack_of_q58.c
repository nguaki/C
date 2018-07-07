#include <stdio.h>
#include <time.h>

int 
main(void)
{
    int i, j;
    
    time_t t0 = time(0);
    clock_t c0 = clock();

    for( i=0; i <1000;i++)
        for( j=0; j <1000000; j++){}
    
    clock_t c1 = clock();
    time_t t1 = time(0);
    double datetime_diff_ms = difftime(t1, t0) * 1000.;
    double runtime_diff_ms = (c1 - c0) * 1000. / CLOCKS_PER_SEC;
    
    printf( "%lf\n", datetime_diff_ms );
    printf( "%lf\n", runtime_diff_ms );
   
    return 0;
}
