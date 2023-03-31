#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define BUF_LEN 256

void* alarm_func(void* arg);

struct alarm_str {
    int sec;
    char msg[BUF_LEN];
    FILE* fp;
    pthread_t pt;
    struct alarm_str *prev;
    struct alarm_str *next;
};

struct alarm_str *head = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv)
{
    struct alarm_str *alarm;
    FILE *fp;
    char line[BUF_LEN];

    if(argc < 2)
        return 1;

    fp = fopen(argv[1], "w");

    while(1) {
        printf("Alarm(sec, msg) -->");
        fgets(line, sizeof(line), stdin);
        if(strlen(line) <= 1)
            continue;

        if(memcmp(line, "quit", 4) == 0)
            break;

        alarm = malloc(sizeof(struct alarm_str));
        if(!alarm) {
            printf("malloc failure");
            return 1;
        }
        alarm->fp = fp;
        if(sscanf(line, "%d %s", &alarm->sec, alarm->msg) < 2)
            continue;

        pthread_mutex_lock(&mutex);
        alarm->next = head;
        alarm->prev = 0;
        if(head) {
            head->prev = alarm;
        }
        head = alarm;
        pthread_mutex_unlock(&mutex);
        pthread_create(&alarm->pt, NULL, &alarm_func, alarm);
        pthread_detach(alarm->pt);
    }

    pthread_mutex_destroy(&mutex);
    fclose(fp);
    return 0;
}

void * alarm_func(void *arg) 
{
    struct alarm_str *alarm = (struct alarm_str *)arg;
    struct alarm_str *current = 0;
    int cnt;

    for(cnt=0; cnt < alarm->sec; cnt++) {
        flockfile(alarm->fp);
        fprintf(alarm->fp, "[%d] (%d); %s\n",
                alarm->sec, cnt, alarm->msg);
        fflush(alarm->fp);
        funlockfile(alarm->fp);
        sleep(1);
    }

    pthread_mutex_lock(&mutex);
    for(current = head; current; current = current->next) {
        if(current->pt != pthread_self())
            continue;

        if(current->next != 0)
            current->next->prev = current->prev;

        if(current->prev != 0)
            current->prev->next = current->next;

        if(head == current)
            head = current->next;

        break;
    }
    free(current);
    pthread_mutex_unlock(&mutex);
    return 0;
}
