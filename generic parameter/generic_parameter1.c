
////////////////////////////////////////////////////////////////////
//
// April 6, 2017
// 
// generic_parameter1.c
//
// Parameters can be general since it can take any types.
//
// Note that it void pointer variables can be utilized only thru
// assignment of type pointer variables.
// Please read below.
//
// OUTPUT
// iResult = 15
// iResult = 15.900000
//
/////////////////////////////////////////////////////////////////////
#include <stdio.h>

void
sum_anything( void *a, void *b, unsigned short sType, void *result )
{
    int    *p1,  *p2,  *res1;
    double *dp1, *dp2, *dres1;
    
    
    if( sType == 1 )
    {
        //if a is a pointer to int like the following statement
        //    int *a;
        //    p1 = a;  would be sufficient.
        //However, since a is pointer to void, it requires a int pointer typecast:
        p1 = (int *)a;
        p2 = (int *)b;
        res1 = (int *)result;
        
        *res1 = *p1 + *p2;
        
        //printf( "a = %d", (int)*a);   Conceptually makes a sense, but this is 
        //                              not allowed in C. 
        //                              Conceptually this makes a perfect sense
        //                              *a is dereferencing from a memory and
        //                              since 'a' is of a pointer to void, by typecasting
        //                              it with (int) will make this an int.
        //                              Apparently C does not allow this.
        //int result;
        //result = (int)*a + (int)*b;   Again conceptually makes a sense but simply
        //                              not allowed in C.
    }
    else
    {
        dp1 = (double *)a;
        dp2 = (double *)b;
        dres1 = (double *)result;
        
        *dres1 = *dp1 + *dp2;
    }
}

int
main()
{
        int i = 5, j = 10;
        int    iResult;
        double d1= 5.5, d2 = 10.4;
        double dResult;
      
        sum_anything( &i, &j, 1, &iResult );
        printf( "iResult = %d\n", iResult ); 

        sum_anything( &d1, &d2, 2, &dResult );
        printf( "iResult = %f\n", dResult ); 
    
       return 0;
}