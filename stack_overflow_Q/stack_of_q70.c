#include <stdio.h>
#include<string.h>



int main()
{

 char *token;
 char *token2;
char line[] = "-500,600";
char *search = ",";


printf("%s\n",line);


token = strtok(line, search);
printf("token1: %s\n",token);


token2 = strtok(NULL, search);
printf("token2: %s\n",token2);  


 int n = toInt(token);
 int m = toInt(token2);

  printf("String  = %s\nInteger = %d\n", token, n);
   printf("String  = %s\nInteger = %d\n", token2, m);

  int b = n*3;
  int c = m*2;

    printf("%d\n",b);
    printf("%d",c);



  return 0;
}

int toInt(char a[]) {
  int c, sign = 0;  //The crux of the problem.  If sign is not set, it can be set to -1. So it is safe to set it to 0.
                    //The problem was with a = 600.  Although the sign char doesn't exists. The sign var
                    //was assigned to -1. So the offset became 1.  So the calculation started from 00, not 600.
  int offset, n;

  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }

  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }

  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1) {
    n = -n;
  }

  return n;
}