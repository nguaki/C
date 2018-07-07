#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//#define SUN_DAY 1   //This definitions cannot conflict with enum days members.
//#define MONDAY  2
//#define TUESDAY 3
#define WED_DAY 4
#define PI 3.14156

typedef enum days {SUNDAY, MONDAY, TUESDAY, WEDDAY, THURDAY, FRIDAY, SATDAY } DAYS_TYPE;

DAYS_TYPE my_wedding_day;

/* Causes all kinds of warning messages.
#ifndef WED_DAY
       my_wedding_day= rand() % 7;  //This is not static assignment, but dynamic assignment.
                                    //Therefore, this code must reside within main.
#else
       my_wedding_day= WEDDAY;
#endif
*/
int
main(void)
{
    srand(time(NULL));
#ifndef WED_DAY
       my_wedding_day= rand() % 7;  //This is not static assignment, but dynamic assignment.
                                    //Therefore, this code must reside within main.
#else
       my_wedding_day= WEDDAY;
#endif

   printf("%d\n", my_wedding_day );
    
    return 0;
}