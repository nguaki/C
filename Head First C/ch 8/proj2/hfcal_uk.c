//
// Jan 29, 17
//
// hfcal_uk.c
//
//This software is for the UK treadmill which will display
//in kg, meter.
#include <stdio.h>
#include "hfcal.h"

void
display_calories( float weight, float distance, float coefficient )
{
    printf( "Weight: %3.2f kg\n", weight );
    printf( "Distance: %3.2f km\n", distance );
    printf( "Calories burned: %4.2f cal\n", weight*distance*coefficient );
}