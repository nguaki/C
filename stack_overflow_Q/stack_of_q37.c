#include <stdio.h>
#include <string.h>

int
main(void)
{
    char courseName[20];
    char grade;
    float credit;
    char *a_string = "Biology    A 4.0";
    
    sscanf( a_string, "%s %c %f", courseName, &grade, &credit );

    
    return 0;
}