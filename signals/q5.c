5. Write a program which takes a value of delay as command line
argument and creates a child process. The parent process waits for the
child process to finish its job up to the supplied delay value. If the child
terminates within the delay the parent prints the termination status
and PID of the child process. On not receiving from the child it kills the
child process forcefully.



  #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int delay;
    pid_t pid;
    int status;

    if (argc != 2)
    {
        printf("Usage: %s <delay>\n", argv[0]);
        return 1;
    }

    delay = atoi(argv[1]);

    pid = fork();

    if (pid == 0)
    {
        printf("Child process started\n");

        sleep(3);

        printf("Child process finished\n");

        return 10;
    }
    else
    {
        printf("Parent is waiting for %d seconds\n", delay);

        sleep(delay);

        if (waitpid(pid, &status, WNOHANG) == 0)
        {
            printf("Child did not finish within the delay\n");
            printf("Killing child process...\n");

            kill(pid, SIGKILL);

            waitpid(pid, &status, 0);

            printf("Child process killed\n");
        }
        else
        {
            printf("Child process finished within the delay\n");
            printf("Child PID = %d\n", pid);

            if (WIFEXITED(status))
            {
                printf("Termination status = %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
