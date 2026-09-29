1. Write a program to create a child process. The parent catches a SIGCHLD
signal from the child process when the child terminates (the child sends
SIGCHLD when either it is interrupted or it resumes after being
interrupted).



#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void childHandler(int signal)
{
    printf("SIGCHLD received: Child has terminated\n");
    wait(NULL);
}

int main()
{
    pid_t pid;

    signal(SIGCHLD, childHandler);

    pid = fork();

    if (pid == 0)
    {
        printf("Child process is running\n");

        sleep(2);

        printf("Child process is terminating\n");
    }
    else
    {
        printf("Parent process is waiting\n");

        sleep(5);
    }

    return 0;
}
