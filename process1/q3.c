3. Implement an orphan process using fork.





#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process started\n");

        sleep(5);

        printf("Child PID = %d\n", getpid());
        printf("New Parent PID = %d\n", getppid());
    }
    else
    {
        printf("Parent process\n");
        printf("Parent PID = %d\n", getpid());

        sleep(1);

        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}
