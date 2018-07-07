#include <stdio.h>
#include <string.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <stdlib.h>  // for strtol

struct key_store
{
    char *key;
}store[1024];


int STORED=0;

void put(char *key)
{
    int i;
    for (i=STORED;i<1024;i++)
    {
        store[i].key=strdup(key);
        STORED++;
        break;
    }
}

void handler(int socket_desc)
{
    int client_sock;
    char client_message[1024];

    client_sock = accept(socket_desc, (struct sockaddr *) NULL, NULL);
    printf("Connection accepted\n");
    while( read(client_sock , client_message , 100) > 0 )
    {
        put(client_message);
    }
    close(client_sock);
}


int main(int argc , char *argv[])
{   
int socket_desc;
struct sockaddr_in server;

server.sin_port = htons( 8888 );

//Create socket
socket_desc = socket(AF_INET , SOCK_STREAM , 0);
if (socket_desc == -1)
{
    printf("Could not create socket");
}
printf("Socket created\n");

//Prepare the sockaddr_in structure
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family = AF_INET;

//Bind
if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
{
    //print the error message
    perror("bind failed. Error");
    return 1;
}
printf("bind done\n");

//Listen
listen(socket_desc , 5);

int count =0, i;
while(count < 3)
{
    handler(socket_desc);
    count++;
}

close(socket_desc);

for (i=0;i<STORED;i++)
{
    printf("KEY --> %s\n",store[i].key); //In the end(when count=2 print the store keys)
}

return 0;
}