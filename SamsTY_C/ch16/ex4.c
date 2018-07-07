// Feb 16, 17
//
// Lesson 16 exercise 4.
//
//Demonstration of array of pointers to type double.
//Each index is a pointer to an indice of double array.
//Sorts these array.
//
//
/*
Enter a num:5.5
Enter a num:4.4
Enter a num:7.8
Enter a num:9.2
Enter a num:4.2
5.500000
4.400000
7.800000
9.200000
4.200000
After sort 
4.200000
4.400000
5.500000
7.800000
9.200000
*/
#include <stdio.h>
#include <stdlib.h>

double *p_d[10];
void sort();


#define MAX 5

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
        
    sort();
    printf("After sort \n");
    for( i=0; i<MAX; i++ )
        printf( "%lf\n", *p_d[i] );
    
    
    return 0;
}

void
sort()
{
    double *d;
    int a, b;
    
    for( a=1; a<MAX; a++)
        for( b=0; b<MAX-1;b++){
            if( *p_d[b] > *p_d[b+1]){
                d = p_d[b];
                p_d[b] = p_d[b+1];
                p_d[b+1] = d;
            }
        }
}
