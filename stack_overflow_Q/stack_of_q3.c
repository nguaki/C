#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//Initialize memory pointed by p with values 0 1 ... n
//Assumption : the value of n can be converted to 
//             short int (without over/under-flow)
unsigned int initArr (short int *p, unsigned int n);

int main (void)
{
  static const unsigned int numOfElem = USHRT_MAX;
  short *p_arr = (short *) malloc (numOfElem * sizeof (short));
  unsigned int lastValSet = initArr (p_arr, numOfElem);    //returns the "max" val written

  for (unsigned int i = 0; i < numOfElem; i++)
    if (i > SHRT_MAX - 1)
      printf ("[%d]=%d \n", i, (*(p_arr + i)));

  return lastValSet;
}


unsigned int 
initArr (short *p, unsigned int n)
{
  unsigned int index = 0;

  while (index < n)
      *(p + index) = (-1 + (++index)); //is this robust?

  return index - 1;
}