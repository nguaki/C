#include <stdio.h>
#include <string.h>

int
main(void)
{
char *line = "   \"abc\" : \"123\" ";
printf( "%s\n", line );
char res[100];

char *q1 = strchr(line, '\"'); /* needs error checking */
char *q2 = strchr(q1 + 1, '\"');
char *q3 = strchr(q2 + 1, '\"');
char *q4 = strchr(q3 + 1, '\"');

/* allocate res */
sprintf(res, "%.*s", (int)(q4 - q3 - 1), q3 + 1);
printf("%s\n", res);

printf("%.*s\n", 3, "Hello World");  //Only prints "Hel" 
printf("%.3s\n",  "Hello World");  //Only prints "Hel" 
}