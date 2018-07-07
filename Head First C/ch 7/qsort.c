//Feb 2, 17
//
//Demonstration of qsort function.
//
#include <stdio.h>
#include <stdlib.h>
/*
-6
0
1
2
5
9
55
===============================
55
9
5
2
1
0
-6
===============================
aaron
david
isaac
joseph
moses
noah
paul
peter
phillip
===============================
phillip
peter
paul
noah
moses
joseph
isaac
david
aaron
===============================
2
12
25
30
49
64
*/

int numbers[] = { 55, 1, -6, 5, 0, 2,9 };
char *bibleNames[] = { "david", "joseph", "noah", "moses", "aaron", "paul", "peter", "phillip", "isaac" };
typedef struct{
    int length;
    int width;
}RECTANGLE;

RECTANGLE rect[] = { {3,4}, {5,6}, {1,2}, {5,5}, {7,7}, {8,8} };

//Sort by area of a rectangle.
int
ascending_area( const void *a, const void *b )
{
    RECTANGLE *ra = (RECTANGLE *)a;
    RECTANGLE *rb = (RECTANGLE *)b;
    
    int area1 = ra->length * ra->width;
    int area2 = rb->length * rb->width;
    
    return (area1 - area2);
}

//sort by names.
int
ascending_names( const void *a, const void *b )
{
    
    char **sa = (char **)a; //weird!!
    char **sb = (char **)b;
    
    return strcmp(*sa, *sb);
    
}
int
descending_names( const void *a, const void *b )
{
    
    char **sa = (char **)a;
    char **sb = (char **)b;
    
    return strcmp(*sb, *sa);
    
}

//Sort by ascending order of numbers.
int
ascending_order( const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    
    return x-y;

}

//Sort by descending order of numbers.
int
descending_order( const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    
    return y - x;

}
void
display()
{
    int i;
    
    for( i = 0; i < 7; i++)
        printf( "%d\n", numbers[i]);
}
void
displayNames()
{
    int i;
    
    for( i = 0; i < 9; i++)
        printf( "%s\n", bibleNames[i]);
}

void
displayRect()
{
    int i;
    
    for( i = 0; i < 6; i++)
        printf( "%d\n", rect[i].length * rect[i].width);
}
int
main()
{

    qsort( numbers, 7, sizeof(int), ascending_order );
    
    display();

    printf( "===============================\n" );
    qsort( numbers, 7, sizeof(int), descending_order );
    
    display();
    
    printf( "===============================\n" );
    qsort( bibleNames, 9, sizeof(char *), ascending_names );
    
    displayNames();
    printf( "===============================\n" );
    qsort( bibleNames, 9, sizeof(char *), descending_names );
    
    displayNames();
    printf( "===============================\n" );

    qsort( rect, 6, sizeof(RECTANGLE), ascending_area );
    displayRect();
    return 0;
}
