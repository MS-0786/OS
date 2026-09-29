1. Write a program to create a thread that displays a WELCOME message.



  #include <stdio.h>
#include <pthread.h>

void *welcome(void *arg)
{
    printf("WELCOME\n");

    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, welcome, NULL);

    pthread_join(thread, NULL);

    return 0;
}
