/* gcc alarm_single.c -o alarm_single -g -W -Wall */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

int main(int argc, char* argv[]) {

    struct sigaction sa;
    int sec = 0;
    int i = 0;
    char line[256];
    char msg[256];
    pid_t pid = 0;

    if(argc < 2) 
        return 1;
    FILE *fp = fopen(argv[1], "w");
    if(fp == 0) {
        return 1;
    }

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGCHLD, &sa, 0);


    while( 1 ) {
        printf( "Alarm ( sec msg ) --> " );
        fgets( line, sizeof( line ), stdin );
        if( strlen( line ) <= 1 ) {
            continue;
        }
        if( memcmp( line, "quit", 4 ) == 0 ) {
            break;
        }
        line[strlen( line ) - 1] = '\0';
        if( sscanf( line, "%d %s", &sec, msg ) < 2 ) {
            continue;
        }
        
        pid = fork();
        if(pid == 0) {
            fprintf(fp, "[%d] (%d) %s\n", sec, i, msg);
            fflush(fp);
            sleep(1);
        }
    }
    fclose(fp);
    kill(-(getpid()), SIGINT);
    return 0;
}
