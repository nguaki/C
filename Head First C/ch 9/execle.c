// Jan 29, 17
//
// Exercising execle() command.
//
/*
# of Diners:2
Dish: chicken
Dish: beef
DRINK: ORANGE JUICE
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int
main()
{

    char *myEnv[] = { "DRINK=ORANGE JUICE", NULL };
    
    //Need to specify path.
    if( execle( "/home/ubuntu/workspace/Head First C/ch 9/diner", "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "chicken", "beef", NULL, myEnv ) == -1 )
    {
        //fprintf( stderr, "Cannot run diner: %s", strerror(errno));
        printf( "Cannot run diner\n");
        return 1;
    };

    return 0;
}