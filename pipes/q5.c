5. Write a program that creates one-way pipe between a parent and three
child processes. The parent process gets an integer number range from

standard input and divides the entire range to three child processes.
Each of the child after receiving the sub-range, searches for prime
numbers in that range and prints them.


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int prime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

void child(int fd[2])
{
    int r[2];

    close(fd[1]);
    read(fd[0], r, sizeof(r));

    printf("Range %d to %d: ", r[0], r[1]);

    for (int i = r[0]; i <= r[1]; i++)
        if (prime(i))
            printf("%d ", i);

    printf("\n");
}

int main()
{
    int p[3][2];
    int r[3][2];
    int start, end, part;

    for (int i = 0; i < 3; i++)
        pipe(p[i]);

    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

    part = (end - start + 1) / 3;

    r[0][0] = start;
    r[0][1] = start + part - 1;

    r[1][0] = start + part;
    r[1][1] = start + 2 * part - 1;

    r[2][0] = start + 2 * part;
    r[2][1] = end;

    for (int i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {
            child(p[i]);
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        close(p[i][0]);
        write(p[i][1], r[i], sizeof(r[i]));
        close(p[i][1]);
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    return 0;
}
