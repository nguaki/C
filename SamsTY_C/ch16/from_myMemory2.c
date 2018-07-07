// Feb 17, 2017
// finish time: 43:12
// Was able to figure it out on my own using gdb.
// Was able to fix a bug from previous try.
//
#include <stdio.h>
#include <stdlib.h>

struct single_char{
    char c;
    struct single_char *next;
};

typedef struct single_char SC;
typedef SC *P_SC;

#define MAX 5

P_SC addChar( P_SC first, char c );
void printNodes( P_SC first);


int
main(void)
{
    P_SC first = NULL;
    int i;
    char c, garbage[80];
    
    
    for( i=0; i<5; i++){
        printf( "Enter a char:" );
        scanf( "%c", &c );
        gets(garbage);
    
        first = addChar( first, c ); 
        
        printf( "first = %c\n", first->c);
        printf ("So far, the list is \n" );
        printNodes(first);
    }
    
    printNodes(first);

    return 0;
}

P_SC 
addChar( P_SC first, char c )
{
    P_SC new_rec, curr_rec, prev_rec;
    
    new_rec  = NULL;
    curr_rec = NULL;
    prev_rec = NULL;
    
    new_rec = (P_SC)malloc(sizeof(SC));
    if (new_rec == NULL){
        printf("Cannot allocate memory.");
        exit(1);
    }
    
    new_rec->c = c;
    new_rec->next = NULL;
    
    if ( first == NULL )
    {
        first = new_rec;
    }
    else
    {
        if ( new_rec->c <= first->c )
        {
            new_rec->next = first;
            first = new_rec;
        }
        else
        {
            curr_rec = first->next;
            prev_rec = first;
            
            if (curr_rec == NULL)
            {
                prev_rec->next = new_rec;
            }
            else
            {
                while(curr_rec->next != NULL)
                {
                    if (new_rec->c <= curr_rec->c){
                        new_rec->next = curr_rec;
                        prev_rec->next = new_rec;
                        break;
                    }else{
                        curr_rec = curr_rec->next;
                        prev_rec = prev_rec->next;
                    }
                }
                
                if (curr_rec->next == NULL){
                    if (new_rec->c <= curr_rec->c){
                        new_rec->next = curr_rec;
                        prev_rec->next = new_rec;
                    }else{
                        curr_rec->next = new_rec;
                        new_rec->next = NULL;
                    }
                }
            }
        }
    }
    return first;
}

void printNodes( P_SC first)
{
    P_SC t;
    
    t = first;
    
    while( t != NULL ){
        printf( "%c\n", t->c );
        t = t->next;
    }
}

