//Feb 16, 17
//
//Demonstration of linked list.
/*
Angela
James
Matthew
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person{
    char name[20];
    struct person *next;
}PERSON;

PERSON *person;

int
main(void)
{
    PERSON *head = NULL, *new = NULL, *current = NULL;
    
    //Create a node at the head.
    new = (PERSON *)malloc(sizeof(PERSON));
    strcpy( new->name, "Angela" );
    new->next = NULL;
    head = new;
    
    //Create a node at the end.
    current = head;
    while( current->next != NULL )
        current = current->next;
        
    new = (PERSON *)malloc(sizeof(PERSON));
    new->next = NULL;
    strcpy( new->name, "Matthew" );
    current->next = new;
    
    //Insert a node after head.
    new = (PERSON *)malloc(sizeof(PERSON));
    new->next = head->next;
    strcpy( new->name, "James" );
    head->next = new;
  
    //print out
    current = head;
    while( current != NULL ){
        printf( "%s\n", current->name );
        current = current->next;
    }

    return 0;
}