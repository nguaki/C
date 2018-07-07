// Jan 29, 17
//
// Demonstration of execv() command.
//
/*
# of Diners:2
Dish: Chicken
Dish: Beef
DRINK: (null)
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int
main()
{

    char *myArgs[]  = { "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "Chicken", "Beef", NULL };
    //Need to specify path.
    if( execv( "/home/ubuntu/workspace/Head First C/ch 9/diner", myArgs ) == -1 )
    {
        //fprintf( stderr, "Cannot run diner: %s", strerror(errno));
        printf( "Cannot run diner\n");
        return 1;
    };

    return 0;
}