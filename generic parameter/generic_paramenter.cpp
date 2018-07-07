#include <stdio.h>
/*
OUTPUT
15
15
15.900000
15.900000
res1 = 15
iResult = 15
dres1 = 15.900000
iResult = 15.900000
*/
int n;
double d;

//
// sum_int is a function which returns a pointer to void.
// When returning a pointer to void, this can returns a pointer to any type.
// 
// In this case, n is a global integer.
// This function returns the address of n variable.
//
void *
sum_int( void *a, void *b )  //Can be any type/
{
    int *p1 = (int *)a;      //Typecast to int pointer
    int *p2 = (int *)b;      //Typecast to int pointer
    n = *p1 + *p2;
    n = *((int *)a) + *((int *)b);
    return &n;
}

void
sum_anything( void *a, void *b, unsigned short sType, void *result )
{
    int *p1, *p2, *res1;
    double *dp1, *dp2, *dres1;
    
    
    if( sType == 1 )
    {
        p1 = (int *)a;
        p2 = (int *)b;
        res1 = (int *)result;  //res1 points to result.
        
        *res1 = *p1 + *p2;//the value is modified at this address.
        printf( "res1 = %d\n", *res1);
    }
    else
    {
        dp1 = (double *)a;
        dp2 = (double *)b;
        dres1 = (double *)result;
        
        *dres1 = *dp1 + *dp2;
        printf( "dres1 = %f\n", *dres1 );
    }
    
}
//
//
//
//
void *
sum_double( void *a, void *b )
{
    double *p1 = (double *)a;
    double *p2 = (double *)b;
    d = (*p1 + *p2);
    return &d;
}

// op is a function pointer that returns void pointer.
void *
process( void *a, void *b, void *(*op)(void *, void *))
{
    void *result = op(a,b);   
 
    return result;
}

int
main()
{
       
        int *result;
        int i = 5, j = 10;
        void *vResult;
        int  iResult;
        double dResult;
        
        result = (int *)sum_int(&i,&j); //result is a pointer to int.  So bascially result gets the
                                        //returned address.
        printf( "%d\n", *result);  //Should return 15.
        
        void *(*op)(void *, void *);//op is a functional pointer that returns void *.
        op = sum_int; //Remember each function is an address.
        
        result = (int *)process( &i,&j,op); //This is calling sum_init().
        printf( "%d\n", *result);
        ///////////////////////////////////////////////////////
        double *dresult;
        
        double d1= 5.5, d2 = 10.4;
        dresult = (double *)sum_double(&d1,&d2);
        
        printf( "%f\n", *dresult);
        
        op = sum_double; //Function pointer now points to sum_double function.
        
        dresult = (double *)process( &d1, &d2, op );
        printf( "%f\n", *dresult);
      
        //////////////////////////////////////////////////////////////////
        sum_anything( &i, &j, 1, &iResult );  //Calls adding integers
        printf( "iResult = %d\n", iResult ); 

        sum_anything( &d1, &d2, 2, &dResult ); //Calls adding doubles
        printf( "iResult = %f\n", dResult ); 
    
       return 0;
}