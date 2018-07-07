#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


char sir[100];

int vocal(char x)  
{

  if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A'|| 
  x=='E' || x=='I' || x=='O' || x=='U')
return 1;
return 0;

}
int main(){
int i, j, pid_status;

printf("Read the text: \n");
//read(1,sir,100); // file descriptor is 1;
fgets(sir,100, stdin);
printf("sir = %s\n", sir);

pid_t a_Process;

for( i=0;i<strlen(sir);i++)
{

  if(vocal(sir[i])==1)
  {
    printf("detected a vowel\n");
    
    a_Process=fork();
    if( a_Process == -1 ){
        fprintf(stderr, "Can't fork a process.\n");
        return 1;
    }
    
    if(a_Process){
        printf("Starting a new child .... \n");
        for(j=i;j<strlen(sir)-1;j++)
            sir[j]=sir[j+1];
    }               
    if( waitpid(a_Process, &pid_status, 0 ) == -1){
        printf("Error waiting for child process.\n");
    }
  }
}
 printf("%s",sir);
  return 0;
}