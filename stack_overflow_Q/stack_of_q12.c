#include <stdio.h>
#include <string.h>
#include <time.h>

char *
strskip(const char * s, const char * t) {
  const char * p;
  if ((p = strstr(s,t))) {
    return (char *) p + strlen(t);
  }
  return NULL;
}

/*
event_channel(irc_session_t * session, const char * event, const char * origin, const char ** params, unsigned int count) {
  log_event(session, event, origin, params, count);

  const char * cmd = params[1];
  char * p;

  char * b = strchr(origin,'!');
  char sender[16];
  strncpy(sender,origin,b-origin);
  sender[b-origin] = '\0';
  char msg[64];
  printf("sender %s\n",sender);

  if ((p = strskip(cmd,nickname)) && strskip(p,"say hello")) {
    sprintf(msg,"hello %s",sender);
    irc_cmd_msg(session,params[0], msg);
    return;
  }

  if ((p = strskip(cmd,nickname)) && strskip(p,"time")) {
    time_t clock = time(NULL);
    struct tm * tm = localtime(&clock);
    char buf[32];
    strftime(buf,32,"%d/%m/%Y @ %H:%M:%S",tm);
    irc_cmd_msg(session,params[0], msg);
    return;
  }

  if ((p = strskip(cmd,nickname)) && strskip(p,"help")) {
    printf("say \"say hello\" for the bot to say hi. \n");
    printf("say \"time\" to find out what time it is.\n");
    irc_cmd_msg(session,params[0], msg);
    return;
  }
*/
int
main(int argc, char **argv)
{
  char cmd[30];
  char * p;

  strcpy(cmd, "bot help");
  //char * b = strchr(origin,'!');
  char sender[16] = "James";
  //strncpy(sender,origin,b-origin);
  //sender[b-origin] = '\0';
  char msg[64];
  //printf("sender %s\n",sender);
  char *nickname = "bot";

  printf( "cmd = %s\n", cmd );
  p = strskip(cmd,nickname);
  
  printf("p = %s\n", p);
  if (strskip(p,"say hello")) {
    sprintf(msg,"hello %s",sender);
    //irc_cmd_msg(session,params[0], msg);
    printf("%s\n", msg);
    return;
  }

  if ((p = strskip(cmd,nickname)) && strskip(p,"time")) {
    time_t clock = time(NULL);
    struct tm * tm = localtime(&clock);
    char buf[32];
    strftime(buf,32,"%d/%m/%Y @ %H:%M:%S",tm);
    //irc_cmd_msg(session,params[0], msg);
    printf("buf = %s\n", buf );
    return;
  }

  if ((p = strskip(cmd,nickname)) && strskip(p,"help")) {
    printf("say \"say hello\" for the bot to say hi. \n");
    printf("say \"time\" to find out what time it is.\n");
    //irc_cmd_msg(session,params[0], msg);
    return;
  }
  }