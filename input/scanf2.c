#include<stdio.h> 

int main(void)
{ 
   int n; 
   char garbage[40];
   
   
   scanf("%d", &n); 
   fgets( garbage, sizeof(garbage), stdin);
   printf("BYE\n"); 

   return 0;
}