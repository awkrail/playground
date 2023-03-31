#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

void * thread_function(void* arg);

int main(int argc, char **argv)
{
    (void)argc;
    pthread_t pt;
    char * rtn_p = 0;
    char buf[256];

    strcpy(buf, argv[0]);
    fprintf(stdout, "buf :[%s]\n", buf);
    pthread_create(&pt, NULL, &thread_function, (void*)buf);
    pthread_join(pt, (void**)&rtn_p);
    fprintf(stdout, "rtn_p: %s\n", rtn_p);
    return 0;
}

void * thread_function(void *arg)
{
    char* buf = malloc(strlen((char *)arg)+1);
    strcpy(buf, (char*)arg);
    size_t i;
    for(i=0; i<strlen(buf); ++i) {
        buf[i] = toupper(buf[i]);
    }
    pthread_exit(buf);
}
