#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  char **E = malloc(3*sizeof(char *));
  const char *e[3] = {"aa", "bb", "cc"};
  int k;
  
  for (k=0; k<3; k++)
  {
      //E[k] = (char *)malloc(sizeof(char));
      //(E[k], e[k]); //crash occurs here
  
      E[k] = e[k];
      
      //printf( "%s\n", E[k]);
  }
  for( k=0; k<3; k++ )
  {
      printf( "%s\n", E[k]);
  }
  
  
  return 0;
}