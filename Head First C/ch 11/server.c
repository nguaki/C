// Feb 2, 17
//
//Knock Knock protocol.
//BLAB - 
//       Bind a port, Listen, accept, begin talking
//
/*
from server:
dguai:~/workspace/Head First C/ch 11 $ ./server
Waiting for connection 
*/
/*
from client:(can open as many clients.)
dguai:~/workspace $ nc 127.0.0.1 30000
Internet Knock-Knock Protocol Server 
Version 1.0
Knock! Knock!
>Who's there?
Oscar
>oscar who?
Oscal silly question, you get a silly answer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int catch_signal( int sig, void (* handler)(int) )
{
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    
    return sigaction( sig, &action, NULL );
}
void
error( char *msg )
{
    fprintf( stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int
open_listener_socket()
{
    //Establish a socket.
    int listener_id = socket( PF_INET, SOCK_STREAM, 0 );
    
    if( listener_id == -1 ){
        error( "Cannot open a socket.\n" );
    }

    return listener_id;
}

void
bind_to_port( int sock_id, int port_number )
{
    //In order to reuse the port.
    int reuse = 1;
    if( setsockopt(sock_id, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error( "Can't set the reuse option.\n");
    
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port   = (in_port_t)htons(port_number);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int c = bind( sock_id, (struct sockaddr *)&name, sizeof(name) );
    
    if( c == -1 )
        error( "Cannot bind.\n");
}

  
int 
say( int sock_id2, char *message )
{
    //Send a message to a client.
    int result = send( sock_id2, message, strlen(message), 0);
    if (result == -1 )
        fprintf( stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
    
    return result;
}

int g_socket_id;

void 
handle_shutdown( int sig )
{
    if (g_socket_id)
        close(g_socket_id);
        
    fprintf( stderr, "Closing port %d.\n", g_socket_id);
    exit(0);
}
int
read_in( int sock_id2, char *buf, int len )
{
    char *s = buf;
    int  slen = len;
    int c = recv( sock_id2, s, slen, 0);
    
    while( (c>0) && (s[c-1] != '\n')){
        slen = slen - c;
        s = s + c;
        c = recv( sock_id2, s, slen, 0 );
    }
    
    if (c<0)
        return c;
    else if (c==0)
        buf[0] = '\0';
    else
        s[c-1] = '\0';
        
    return len - slen;
}

int
main()
{
   //establish SIGINT handler.
   if (catch_signal(SIGINT, handle_shutdown) == -1){
        error( "cannot shutdown a port.\n");
    }
    
    
    int socket_id = open_listener_socket();
    
    g_socket_id = socket_id;
    
    //Bind
    bind_to_port( socket_id, 30000 );

    //Listen
    if( listen( socket_id, 10 ) == -1 )
        error( "Cannot listen.\n");
    
    puts( "Waiting for connection ");
    
    char buf[255];
    while(1)
    {
        struct sockaddr_storage client_addr;
        
        unsigned int address_size = sizeof(client_addr);
        
        //Accept a connection from a client. 
        int socket_id2 = accept( socket_id, (struct sockaddr *)&client_addr, &address_size);
    
        if (socket_id2 == -1)
            error("Can't open secondary socket.\n");
            
        //Use child process in order to connect with many clients.
        if ( !fork() )    
        {
            close(socket_id);
            //char *mg = msg[rand()%5];
            if( say( socket_id2, 
                "Internet Knock-Knock Protocol Server \r\nVersion 1.0\r\nKnock! Knock!\r\n>" ) != -1 )
            {
                read_in(socket_id2, buf, sizeof(buf));        
            
                //The reply must adhere to this protocol.
                if (strncasecmp("Who's there?",buf,12))
                    say(socket_id2, "You should say 'Who's there?'!");
                else
                {
                    if (say(socket_id2, "Oscar\r\n>") != -1){
                        read_in(socket_id2, buf, sizeof(buf));
                    
                    if (strncasecmp("Oscar who?", buf, 10))
                        say( socket_id2, "You should say 'Oscal who?'!\r\n");
                    else
                        say( socket_id2, "Oscal silly question, you get a silly answer\r\n");
                    }
                }
            }
 
            close(socket_id2);
            exit(0);
        }/*if (!fork() */
        close(socket_id2);
    }/*while()*/
     
    return 0;
}