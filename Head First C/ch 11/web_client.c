// web_client.c
//
// Demonstration of web client.
//
/**
dguai:~/workspace/Head First C/ch 11 $ ./web_client "O'Reilly_Media"
HTTP/1.1 301 Moved Permanently
Date: Thu, 02 Feb 2017 20:09:17 GMT
Server: Varnish
X-Varnish: 567111480
X-Cache: cp4009 int
X-Cache-Status: int
Set-Cookie: WMF-Last-Access=02-Feb-2017;Path=/;HttpOnly;secure;Expires=Mon, 06 Mar 2017 12:00:00 GMT
X-Client-IP: 104.197.56.193
Location: https://en.wikipedia.org/wiki/O'Reilly_Media
Content-Length: 0
Connection: keep-alive
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

void error( char *msg )
{
    fprintf( stderr, "%s: %s\n", msg, strerror(errno) );
    exit(1);
}

int open_socket( char *host, char *port )
{
    struct addrinfo *res;
    struct addrinfo hints;
    
    memset( &hints, 0, sizeof(struct addrinfo));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1 )
        error( "Can't resolve the address" );
        
    int d_sock = socket(res->ai_family,
                        res->ai_socktype,
                        res->ai_protocol);
    if (d_sock == -1)
        error( "Can't open socket" );
    
    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    
    freeaddrinfo(res);
    
    if ( c == -1 )
        error( "Can't connect to socket" );
    
    return d_sock;
}

int
say( int socket, char *s)
{
    int result = send( socket, s, strlen(s), 0);
    if (result == -1)
        fprintf( stderr, "%s:%s\n", "Error talking to the server", strerror(errno));
        
    return result;
}

int
main( int argc, char *argv[] ) 
{
    int d_sock;
    char buf[255];
    char rec[256];
    int bytesRcvd;
    
    d_sock = open_socket( "en.wikipedia.org", "80" );
    
    sprintf( buf, "GET /wiki/%s HTTP/1.1\r\n", argv[1]);
    
    say(d_sock, buf);
    
    say( d_sock, "Host: en.wikipedia.org\r\n\r\n");   
    
    bytesRcvd = recv( d_sock, rec, 255, 0 );
    
    while (bytesRcvd)
    {
        if (bytesRcvd == -1)
            error( "Can't read from server" );
        
        rec[bytesRcvd] = '\0';
        printf( "%s", rec );
        
        bytesRcvd = recv( d_sock, rec, 255, 0 );
    }
    
    close( d_sock );
    return 0;
}