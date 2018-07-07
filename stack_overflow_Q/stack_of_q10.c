#include <stdio.h>
 #include <math.h>

 double calcFutureValue( int numberOfYears);

 const double startingAmount = 10000;
 const double interest = 1.045;

 int main()
 {
     int numberOfYears = 3;
     int i;

    for (i = 0; i < numberOfYears; i++)
    {
        printf("%.2f\n", calcFutureValue(i));
    }

    return 0;
 }


 double calcFutureValue(int numberOfYears)
 {
    return startingAmount * pow(interest, numberOfYears);
 }