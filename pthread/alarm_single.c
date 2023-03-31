/* gcc alarm_single.c -o alarm_single -g -W -Wall */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main( ) {

    int  sec;
    int  cnt;
    char line[256];
    char msg[256];

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
        for( cnt = 0; cnt < sec; cnt ++ ) {
            printf( "[%d] (%d) %s\n", sec, cnt, msg );
            sleep( 1 );
        }
    }
    return 0;
}
