#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client_mod
{    
/* Client ad_file */
 char *ad_filenames[10];
/* Client's current ad array index*/
unsigned int ad_index;

}CLIENT1;

CLIENT1 *client;


int func( char *var1 ) {
client->ad_filenames[0] = strdup(var1);
 }
 
 int
 main(void)
 {
    //char str1[10];
     client = malloc( sizeof client );
     
     //strcpy( str1, "Hello" );
     func( "Hello" );
     
     printf("%s\n", client->ad_filenames[0] );
     
     free(client->ad_filenames[0]);
     free (client);
 
 }