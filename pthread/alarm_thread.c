#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define BUF_LEN 256

void* alarm_func(void* arg);

struct alarm_t {
    int sec;
    FILE* fp;
    char msg[BUF_LEN];
};

int main(int argc, char** argv)
{
    struct alarm_t *alarm;
    pthread_t pt;
    char line[BUF_LEN];

    if(argc < 2)
        return 1;
    FILE* fp = fopen(argv[1], "w");
    if(fp == 0) {
        return 1;
    }

    while(1) {
        printf("Alarm (sec msg) -->");
        fgets(line, sizeof(line), stdin);
        if(strlen(line) <= 1)
            continue;

        if(memcmp(line, "quit", 4) == 0)
            break;

        alarm = malloc(sizeof(*alarm));
        alarm->fp = fp;
        if(sscanf(line, "%d %s", &alarm->sec, alarm->msg) < 2) {
            free(alarm);
            continue;
        }
        pthread_create(&pt, NULL, &alarm_func, alarm);
    }

    fclose(fp);
    return 0;
}

void* alarm_func(void *arg)
{
    struct alarm_t *alarm = (struct alarm_t *)arg;
    int cnt;

    pthread_detach(pthread_self());
    for(cnt = 0; cnt < alarm->sec; cnt++) {
        flockfile(stderr);
        fprintf(stderr, 
                "[%d] (%d) %s \n",
                alarm->sec, cnt, alarm->msg);
        fflush(stderr);
        funlockfile(stderr);
        sleep(1);
    }

    free(alarm);
    return 0;
}
