//Feb 16, 17
//
//Redoing the same program with typedef of a pointer.
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
}NODE;

//PERSON *person;
typedef NODE *PERSON;  //PERSON is type of a pointer to NODE.

//It used to be NODE *head;
//But now PERSON head;
PERSON prev = NULL, head = NULL, new = NULL, current = NULL;  //Remember head, new, current
                                                     //are all pointers.

///////////////////////////////////////////////////////////
//Create a node at the head.
///////////////////////////////////////////////////////////
void
vCreateHeadNode( char *cpName )
{
    new = malloc(sizeof(NODE));
    strcpy( new->name, cpName );
    
    // Before [head] ---> [Node #2]
    // After  [New]  ---> [Head] ----> [Node #2]
    
    //If this is the first one, next is NULL.
    if(head == NULL ) new->next = NULL;
    else new->next = head;
    
    //new node is now head node.
    head = new;

}

///////////////////////////////////////////////////////////
//Insert a node right after the head node.
///////////////////////////////////////////////////////////
void
vInsertNodeAfterHead( char *cpName )
{
    new = malloc(sizeof(NODE));
    strcpy( new->name, cpName );
    
    
    ////////////////////////////////////////////////////////////
    //These steps inserts a new node between head and 2nd node.
    ////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////
    //    Before
    //    [ head ]  --->  [ #2 Node ]
    //    After
    //    [ head ]  --->  [ new ]  ---> [ #2 Node ]
    ////////////////////////////////////////////////////////////
    
    //Step 1. Take care the back side.
    new->next = head->next;
    
    //Step 2. take care the front side.
    head->next = new;
}

///////////////////////////////////////////////////////////
//Create a node at the end.
///////////////////////////////////////////////////////////
void
vInsertAtEnd( char *cpName )
{
    new = (PERSON)malloc(sizeof(NODE));
    strcpy( new->name, cpName );

    //Traverse till the end.
    current = head;
    while( current->next != NULL )
        current = current->next;
        
    // Before [Head] ...  [last node]
    
    // After  [Head] ...  [last node] ---> [new node]
    
    //step 1. Take care the back side.
    new->next = NULL;
    
    //Step 2. Take care the front side.
    current->next = new;

}

int
main(void)
{
    
    vCreateHeadNode( "Angela" );

    vCreateHeadNode( "John" );
    
    vInsertNodeAfterHead( "James" );

    vInsertAtEnd( "Matthew" );
    
    ///////////////////////////////////////////////////////////
    //print out
    ///////////////////////////////////////////////////////////
    current = head;
    while( current != NULL ){
        printf( "%s\n", current->name );
        current = current->next;
    }

    //Free memory
    current = head;
    prev = current;
    while( current != NULL ){
        current = current->next;
        printf("freeing %s node.\n", prev->name);
        free(prev);
        prev = current;
    }
    
    return 0;
}