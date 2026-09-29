2. Write a multi-threaded program where the main thread gets an integer
number range from the user and then creates two child threads; one
thread calculates the sum of all numbers in the range and prints it, and
the second thread finds prime numbers in the range and prints them.
The child thread must terminate by returning a value. The parent thread
must wait for the child threads to finish, and it must also print the return
values of the child threads.




#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int start;
    int end;
} Range;

void *calculateSum(void *arg)
{
    Range *range = (Range *)arg;

    int sum = 0;

    for (int i = range->start; i <= range->end; i++)
    {
        sum = sum + i;
    }

    printf("Sum = %d\n", sum);

    return "Sum thread completed";
}

int isPrime(int number)
{
    if (number < 2)
    {
        return 0;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void *findPrime(void *arg)
{
    Range *range = (Range *)arg;

    printf("Prime numbers: ");

    for (int i = range->start; i <= range->end; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return "Prime thread completed";
}

int main()
{
    pthread_t sumThread, primeThread;

    Range range;

    printf("Enter starting number: ");
    scanf("%d", &range.start);

    printf("Enter ending number: ");
    scanf("%d", &range.end);

    pthread_create(&sumThread, NULL, calculateSum, &range);

    pthread_create(&primeThread, NULL, findPrime, &range);

    void *sumResult;
    void *primeResult;

    pthread_join(sumThread, &sumResult);

    pthread_join(primeThread, &primeResult);

    printf("Sum thread returned: %s\n", (char *)sumResult);
    printf("Prime thread returned: %s\n", (char *)primeResult);

    return 0;
}
