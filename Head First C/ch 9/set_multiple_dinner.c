// Jan 29, 17
//
// Demonstrating execle() command.
// The loop doesn't work since execle() command ends the current process and
// continues the process.  By the time, it ends, it has no where to return.
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

    char *drinks[] = { "ORANGE JUICE", "COKE", "ICE-TEA" };
    char drink[50];

    int i;
    
    
    for( i=0; i<3; i++ ){
    
        sprintf( drink, "DRINK=%s, NULL", drinks[i] );
        char *myEnv[] = { drink, NULL };

        if( execle( "/home/ubuntu/workspace/Head First C/ch 9/diner", "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "chicken", "beef", NULL, myEnv ) == -1 )
        {
            //fprintf( stderr, "Cannot run diner: %s", strerror(errno));
            printf( "Cannot run diner\n");
            return 1;
        };
    }
    
    return 0;
}