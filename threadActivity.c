#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct myArgs {
    int start, finish;
    char *str;
};

void* printString(void *arg);

int main(int argc, char *argv[])
{
    struct myArgs args1, args2;
    char *tmp = "Hello World!";
    pthread_t thread1, thread2;
    args1.start = 0;
    args1.finish = 5;
    args1.str = tmp;
    args2.start = 6;
    args2.finish = 12;
    args2.str = tmp;
    pthread_create(&thread1, NULL, &printString, &args1);
    pthread_create(&thread2, NULL, &printString, &args2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);




    return 0;
}

void* printString(void *arg)
{
    struct myArgs *myArg = (struct myArgs*)arg;
    int i;
    for(i = myArg->start; i < myArg->finish; i++) {
        printf("%c", myArg->str[i]);
    }
}
