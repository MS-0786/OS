3. Write a program which implements thread with arguments and thread
joining.




  #include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    int number = *(int *)arg;

    printf("Number received by thread = %d\n", number);

    return NULL;
}

int main()
{
    pthread_t thread;

    int number = 10;

    pthread_create(&thread, NULL, display, &number);

    pthread_join(thread, NULL);

    printf("Main thread finished\n");

    return 0;
}
