// Feb 16, 17
//
// Uses function pointer to sort an array of numbers
// ascending or descending.
//
/*
Enter a num:6.7
Enter a num:4.5
Enter a num:3.4
Enter a num:8.9
Enter a num:1.0
6.700000
4.500000
3.400000
8.900000
1.000000
After sort 
1.000000
3.400000
4.500000
6.700000
8.900000
After sort 
8.900000
6.700000
4.500000
3.400000
1.000000
*/
#include <stdio.h>
#include <stdlib.h>

double *p_d[10];
void sort( short );


#define MAX 5

int ascending( double *a, double *b );
int descending( double *a, double *b );


int
main(void)
{
    int    i;
    double d[10];
    
    for( i=0; i<MAX; i++)
    {
        printf("Enter a num:");
        scanf("%lf", &d[i]);

        p_d[i] = (double *)malloc(sizeof(double));
        
        p_d[i] = &d[i];
    }

    for( i=0; i<MAX; i++ )
        printf( "%lf\n", *p_d[i] );
        
    sort(1);
    printf("After sort \n");
    for( i=0; i<MAX; i++ )
        printf( "%lf\n", *p_d[i] );
    
    sort(0);
    printf("After sort \n");
    for( i=0; i<MAX; i++ )
        printf( "%lf\n", *p_d[i] );
   
    return 0;
}

void
sort( short sort_type)
{
    double *d;
    int a, b;
    
    int (*xyz)(double *a, double *b);
    
    xyz = sort_type ? ascending : descending;
    for( a=1; a<MAX; a++)
        for( b=0; b<MAX-1;b++){
            if( xyz(p_d[b], p_d[b+1]) > 0){
                d = p_d[b];
                p_d[b] = p_d[b+1];
                p_d[b+1] = d;
            }
        }
}

int
ascending( double *a, double *b )
{
    return( *a - *b );
}
int
descending( double *a, double *b )
{
    return( *b - *a );
}

