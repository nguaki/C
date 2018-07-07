// Jan 29, 17
//
// Demonstrating fork() and execle() command.
// By using child process, now it goes thru all three loop.
// But still there is a problem. 
// These child processes overlap each other.
/*
# of Diners:2
# of Diners:2
Dish: chicken
Dish: chicken
Dish: beef
Dish: beef
DRINK: COKE
DRINK: ORANGE JUICE
# of Diners:2
Dish: chicken
Dish: beef
DRINK: ICE-TEA
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
        sprintf( drink, "DRINK=%s", drinks[i] );
        char *myEnv[] = { drink, NULL };

        pid_t pid = fork();
        
        if( pid == -1 ){
            fprintf( stderr, "Can't fork process. \n" );
            return 1;
        }
        
        if( !pid ){
            
 
            if( execle( "/home/ubuntu/workspace/Head First C/ch 9/diner", "/home/ubuntu/workspace/Head First C/ch 9/diner", "2", "chicken", "beef", NULL, myEnv ) == -1 )
            {
                //fprintf( stderr, "Cannot run diner: %s", strerror(errno));
                printf( "Cannot run diner\n");
                return 1;
            };
        }
    }
    return 0;
}