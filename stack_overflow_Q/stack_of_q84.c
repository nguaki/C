#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
   int valor;
   struct lligada *prox;
} LInt;
typedef struct lligadaX {
   int valor;
   struct lligadaX *prox;
} LIntX;

void remreps( LInt *l )
{
      while (  l != NULL && l->prox != NULL )
      {
          if ( l->valor == l->prox->valor ) 
          {
              LInt *tmp = l->prox;
              l->prox = l->prox->prox;
              free( tmp );
          }
          else 
          {
              l = l->prox;
          }
    }
}


LInt *
push( LInt *l, int valor )
{
    LInt *tmp = malloc( sizeof( *l ) );
    //printf( "sizeof(*l) = %lu\n", sizeof(*l));

    tmp->valor = valor;
    tmp->prox = l;

    return tmp; 
}

void output( LInt *l )
{
    for ( ; l != NULL; l = l->prox )
    {
        printf( "%d ", l->valor );
    }
}

int main(void) 
{
    LInt *l = NULL;
    //printf( "sizeof(l) = %lu\n", sizeof(l));
    //printf( "sizeof(LIntX) = %lu\n", sizeof(LIntX));

    l = push( l, 2 );
    l = push( l, 2 );
    l = push( l, 3 );
    l = push( l, 3 );
    l = push( l, 3 );
    l = push( l, 4 );
    l = push( l, 4 );

    output( l );
    putchar( '\n' );

    remreps( l );

    output( l );
    putchar( '\n' );

    return 0;
}