4. Write a program that creates a two-way pipe between a parent and child
process. The parent process gets an integer from standard input and
sends the integer to the child and the child computes the sum of all
integers up to the input value received from parent and sends the result
back to the parent process, which then prints it. Both the parent and
child terminates when the number 0 is input.


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2], n, sum;
    pipe(p1);
    pipe(p2);

    if (fork() == 0)
    {
        // Child
        close(p1[1]);
        close(p2[0]);

        while (1)
        {
            read(p1[0], &n, sizeof(n));

            if (n == 0)
                break;

            sum = n * (n + 1) / 2;

            write(p2[1], &sum, sizeof(sum));
        }
    }
    else
    {
        // Parent
        close(p1[0]);
        close(p2[1]);

        while (1)
        {
            printf("Enter number: ");
            scanf("%d", &n);

            write(p1[1], &n, sizeof(n));

            if (n == 0)
                break;

            read(p2[0], &sum, sizeof(sum));

            printf("Sum = %d\n", sum);
        }

        wait(NULL);
    }

    return 0;
}
