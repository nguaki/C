// Jan 29, 17
//
// Demonstration of  execlp() command.
//
/*
# of Diners:2
Dish: chicken
Dish: beef
DRINK: (null)
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int
main()
{
    //Need to specify path.
    if( execlp( "/home/ubuntu/workspace/Head First C/ch 9/diner", "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "chicken", "beef", NULL ) == -1 )
    {
        //fprintf( stderr, "Cannot run diner: %s", strerror(errno));
        printf( "Cannot run diner\n";
        return 1;
    };

    return 0;
}