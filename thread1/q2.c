2. Write a program that creates multiple threads and terminate those. The
program should create 5 threads with the pthread_create() routine. Each
thread prints a “Hello World!” message and then terminates with a call
to pthread_exit().




#include <stdio.h>
#include <pthread.h>

void *hello(void *arg)
{
    printf("Hello World!\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[5];

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, hello, NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
