#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node{
    char c;
    struct node *next;
};

typedef struct node NODE;
typedef NODE *DATA;

DATA addChar( char, DATA  );
void traverseNodes(DATA );
void deallocateMem( DATA );

int
main(void)
{
    int i = 0;
    char c, garbage[80];
    DATA  first = NULL;
    
    while( i++ < MAX )
    {
        printf( "Enter a character: " );
        scanf( "%c", &c );
        gets( garbage );
        
        first = addChar( c, first );              
    }
    
    traverseNodes(first);
    deallocateMem(first);
    
    return 0;
}

DATA addChar( char c, DATA first )
{
    DATA new_rec, current, prev;
    
    new_rec = NULL;
    current = NULL;
    prev = NULL;
    
    if( ( new_rec = (DATA)malloc(sizeof(NODE)) ) == NULL ){
        printf( "Cannot allocate memory");
        exit(1);
    }
    new_rec->c = c;
    new_rec->next = NULL;
   
    //if the list is empty.
    if( first == NULL )
    {
        first = new_rec;
        first->next = NULL;
    }
    //if the list is not empty.
    else
    { 
        //if the character is lower than the first.
        if( new_rec->c < first->c )
        {
            new_rec->next = first;
            first = new_rec;
        }
        //if character is greater than the first.
        else
        {
            //printf("stopped here A.\n" );
            current = first->next;
            prev = first;
            
            if ( current == NULL )
            {
               //printf("stopped here A.1.\n" );
               prev->next = new_rec;
            }
            else
            {
                while( current->next != NULL )
                {
                    //insert a new node.
                    if (new_rec->c < current->c )
                    {
                        new_rec->next = current;   
                        prev->next = new_rec;
                        break;
                    }
                    //Move the trackers.
                    else
                    {
                        current = current->next;
                        prev = prev->next;
                    }
                }
            
                //printf("stopped here B.\n" );

                //If traversed at the end.
                if ( current->next == NULL )
                {
                    //printf("stopped here C.\n" );
                
                    //if char is less than the tail end.
                    //Insert right before the end.
                    //printf( "current.c = %c\n", current->c);
                    if( new_rec->c < current->c)
                    {
                        new_rec->next = current;
                        // printf("stopped here D.\n" );
                        prev->next = new_rec;
                        //printf("stopped here E.\n" );
                   
                    }
                    //insert at the end.
                    else
                    {
                        //printf("insert at the end\n");
                        current->next = new_rec;
                        new_rec->next = NULL;
                    }
                }
            }
        }
    }
    return first;
}

void
traverseNodes( DATA first)
{
    DATA traverse;
    int  i = 0;
    
    traverse = first;
    
    puts("ID\tchar\tfrom addr\tto addr");
    puts("====\t=====\t==========\t=========");
    while( traverse != NULL ){
        printf( "%d\t%c\t%p\t%p\n", i++, traverse->c, traverse, traverse->next);
        traverse = traverse->next;
    }
}
void
deallocateMem( DATA first)
{
    DATA traverse, temp;
    int  i = 0;
    
    traverse = first;
    
    while( traverse != NULL ){
        temp = traverse->next;
        printf("freeing %p\n", traverse);
        free(traverse);
        traverse = temp;
    }
}