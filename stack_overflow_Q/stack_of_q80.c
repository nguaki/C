#include <stdio.h>
#include <string.h>

int square( int sum, int i )
{
  return sum * i;
}

int main(int argc, char *argv[])
{
  int sum, i;
  char string[120];
  sum=0;
  strcpy(string, "Hello!");

  for(i=0;i<10;i++) {
    sum+=i;
    sum=square(sum, i);
  }
  printf("sum=%d\n", sum);
  return 0;
}