#include <stdio.h>

int 
main(void)
{
   int n;
   double p=1.0;
   long long llp = 1;
   
   scanf("%d",&n);
   
   if(n>0){
      for(int i=0;i<=n;i++){
         printf("%lld",llp);
         if( i<n) printf(",");
         llp*=2;
      } 
   }else if(n<0){
      for(int i=n;i<=0;i++){
         printf("%.5lf",p);
         if( i<0) printf(",");
         p*=0.5;
      } 
   }else
      printf("1");


   return 0;
}