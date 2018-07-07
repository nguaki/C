#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int count = 0;
  int space_wanted;

  char * res;
  char c;


  res = malloc(1);
  //res[0] ='0';
  *res = 0;   // or *res = '\0';
  
  printf("Instructions: type q to quit. Continually type characters to add"
    " it to the string.\n");

  while ((c = fgetc(stdin)) != EOF && c != 'q')
  {
    //if ( c != 'q' && c != '\n')  // 2 characters are read: a character + newline
    if ( c != '\n')  // 2 characters are read: a character + newline
    {
        //orig = res;

        /* One space for the new character and also for the
        null character */

        space_wanted = strlen(res) + 2;

        //char * new_space = realloc(res, space_wanted = strlen(orig) + 2 );
        //char * new_space = (char *)realloc(res, space_wanted );
        //res = (char *)realloc(res, space_wanted );
        if ( realloc(res, space_wanted ) == NULL)
        {
          fprintf(stderr, "For some reason space was not able to be"
            " allocated.\n");
          return -1;
        }
        res[count++] = c;
        res[count] = '\0';
        printf("res = %s\n", res);

        //res = new_space;

        //memcpy(res, orig, space_wanted);
        //count++;
    } 

  }
  return 0;
}