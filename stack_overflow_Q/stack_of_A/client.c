/*
dguai:~/workspace/C/stack_of_A $ ./client 127.0.0.1 8888 123456
Connection accepted
dguai:~/workspace/C/stack_of_A $ ./client 127.0.0.1 8888 testkey
Connection accepted
dguai:~/workspace/C/stack_of_A $ ./client 127.0.0.1 8888 2017
Connection accepted
KEY --> 123456
KEY --> testkey
KEY --> 2017
*/
#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h> //close
#include <stdlib.h>  // for strtol

int main(int argc , char *argv[])
{

int sock;
struct sockaddr_in server;


//Create socket
sock = socket(AF_INET , SOCK_STREAM , 0);

char *p;
server.sin_addr.s_addr = inet_addr(argv[1]);
int port = strtol(argv[2], &p, 10);
server.sin_port = htons(port);
server.sin_family = AF_INET;
//Connect to remote server
 if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
{
    perror("connect failed. Error");
    return 1;
}
write(sock , argv[3] ,strlen(argv[3])+1); //send the 3rd argument(which is the input key)
close(sock);
return 0;
}