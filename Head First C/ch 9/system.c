// system.c
//
//
//
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *
now()
{
    time_t t;
    
    time(&t);
    return asctime(localtime(&t));
}

int
main()
{
    char comment[80];
    char cmd[120];
    
    fgets( comment, 80, stdin );
    sprintf( cmd, "echo '%s %s' >> report.log", comment, now() );
    
    system(cmd);

    return 0;
}