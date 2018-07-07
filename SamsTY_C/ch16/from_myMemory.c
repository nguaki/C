//  Feb 17, 17
//  
//  Couldn't debug the problem.
//  Had to look into the book.
//  Did word by word comparison.
//  It took 50 minutes to figure it out with the help from the book.
//
// the understanding of the 
// logic flow:  
//  if empty
//  else
//     if new head
//     else
//       if only one node
//       else
//            if node belongs in the middle
//            if node reached the end.
//
//
// gcc -g
//  gdb a.out
//  start
//  step, next
//  run
//  where
//  up (stack)
//  down(stack)
//  list
//  print (p abbr)
//  x (lower level print)
//  x/b (lower level print 1 byte)
//  x/10b
//  p &big
//  watch i
//  cont
//  info watch
//  info break
//  dele 12
// bt (back trace)
// frame 1
// frame 0
// set var sum=23
// quit
//  break 13


#include <stdio.h>
#include <stdlib.h>

struct single_char{
    char c;
    struct single_char *next;
};

typedef struct single_char SINGLE_CHAR;
typedef SINGLE_CHAR *P_SINGLE_CHAR;

#define MAX 5
void printNodes( P_SINGLE_CHAR );
P_SINGLE_CHAR addChar( P_SINGLE_CHAR, char );


int
main(void)
{
    int  i;
    char c, garbage[80];
    
    P_SINGLE_CHAR first;
    
    first = NULL;
    
    for( i=0; i<MAX; i++){
        printf("Enter a char:");
        scanf("%c", &c);
        gets(garbage);
        first = addChar( first, c );
        printf("first is %c\n", first->c);
        
        printf("So far, we have\n" );
        printNodes( first );

    }
    
    printNodes( first );
    return 0;
}

P_SINGLE_CHAR
addChar( P_SINGLE_CHAR first, char c )
{
    P_SINGLE_CHAR new_rec, curr_rec, prev_rec;
    
    new_rec = NULL;
    curr_rec = NULL;
    prev_rec = NULL;
    
    new_rec = (P_SINGLE_CHAR)malloc(sizeof(SINGLE_CHAR));
    if (new_rec == NULL ){
        printf("cannot allocate memory\n");
        exit(1);
    }
    
    new_rec->c = c;
    new_rec->next = NULL;
    
    //if empty list
    if ( first == NULL )
    {
        first = new_rec;
    }
    else
    {
        //if new head, put new record as first node and
        //put the previous first node as second node.
        if (new_rec->c < first->c)
        {
            new_rec->next = first; //Not first->next. Where ever first is located, point at it.
            first = new_rec;       //Now the first points at new record.
        }
        //belongs after head
        else
        {
            curr_rec = first->next;
            prev_rec = first;
            
            //if only one node exists.
            if (curr_rec == NULL)
            {
                prev_rec->next = new_rec;//This will link first to new record.
            }
            //if 2 or more nodes exist.
            else
            {
            
                while(curr_rec->next != NULL)
                {
                    if (new_rec->c < curr_rec->c)
                    {
                        new_rec->next = curr_rec;
                        prev_rec->next = new_rec;
                        break;   // <== important break
                    }
                    else
                    {
                        curr_rec = curr_rec->next;
                        prev_rec = prev_rec->next;
                    }
                }
                
                //If reached the end.
                if (curr_rec->next == NULL)  //equality condition.
                {
                    if (new_rec->c < curr_rec->c)
                    {
                        new_rec->next = curr_rec;
                        prev_rec->next = new_rec;
                    }
                    else
                    {
                        prev_rec->next = new_rec;
                        new_rec->next = NULL;
                    }
                }
            }
        }
    }
        
    return first;
}

void
printNodes( P_SINGLE_CHAR first )
{
    P_SINGLE_CHAR t;
    
    t = first;
    
    while( t != NULL )
    {
        printf( "%c\n", t->c );
        t = t->next;
    }
}
