// April 29, 18
// start time: 1:37AM
// end time  : 1:58AM
// Duration 21 minutes
// Problem & comments: If I cannot draw a picture, I really don't understand
//                     the solution clearly.
//                     Drawing pictures always help.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    char caName[20];
    struct NODE *next;
}NODE;

typedef NODE *PERSON;

PERSON head = NULL, current = NULL, prev = NULL, new = NULL;

void
vInsHead( char *cpName )
{
    new = malloc(sizeof(NODE));
    strcpy(new->caName, cpName);
    
    if(head == NULL) new->next = NULL;
    else new->next = head;
    
    head = new;
}

void
vInsAfterHead( char *cpName )
{
    new = malloc(sizeof(NODE));
    strcpy(new->caName, cpName);
   
    new->next = head->next;
    head->next = new;
}

void
vInsAtEnd( char *cpName )
{
    new = malloc(sizeof(NODE));
    strcpy(new->caName, cpName);

    current = head;
    while( current->next != NULL ) current = current->next;

    new->next = NULL;
    current->next = new;
}
int
main(int argc, char **argv)
{
    vInsHead( "James" );
    vInsAfterHead( "Peter" );
    vInsAtEnd( "afjdajf" );
    vInsHead( "Matthew" );
    
    current = head;
    while(current != NULL){
        printf("%s\n", current->caName);
        current = current->next;
    }
 
    current = head;
    prev = current;
    while(current != NULL){
        current = current->next;
        printf("freeing %s\n", prev->caName);
        free(prev);
        prev = current;
        
    }
    
    return 1;
}