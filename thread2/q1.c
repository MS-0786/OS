1. Write a multi-threaded program where the main thread gets an integer
number range from the user and then creates two child threads; one
thread finds odd numbers in the range and print them, and the second
thread finds even numbers in the range and prints them. The child thread
must terminate by returning a value. The parent thread must wait for the
child threads to finish and it must also print the return values of the child
threads.




#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int start;
    int end;
} Range;

void *findOdd(void *arg)
{
    Range *range = (Range *)arg;

    printf("Odd numbers: ");

    for (int i = range->start; i <= range->end; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return "Odd thread completed";
}

void *findEven(void *arg)
{
    Range *range = (Range *)arg;

    printf("Even numbers: ");

    for (int i = range->start; i <= range->end; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return "Even thread completed";
}

int main()
{
    pthread_t oddThread, evenThread;

    Range range;

    printf("Enter starting number: ");
    scanf("%d", &range.start);

    printf("Enter ending number: ");
    scanf("%d", &range.end);

    pthread_create(&oddThread, NULL, findOdd, &range);

    pthread_create(&evenThread, NULL, findEven, &range);

    void *oddResult;
    void *evenResult;

    pthread_join(oddThread, &oddResult);

    pthread_join(evenThread, &evenResult);

    printf("Odd thread returned: %s\n", (char *)oddResult);
    printf("Even thread returned: %s\n", (char *)evenResult);

    return 0;
}
