4. Process A and Process B normally sleep, except when process A
receives signal SIGUSR1 and process B receives signal SIGUSR2, when
both the processes prints the message “I am awake” and terminate.
Write a program to incorporate this.



  #include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handlerA(int signal)
{
    printf("Process A: I am awake\n");
    _exit(0);
}

void handlerB(int signal)
{
    printf("Process B: I am awake\n");
    _exit(0);
}

int main()
{
    pid_t processA, processB;

    processA = fork();

    if (processA == 0)
    {
        signal(SIGUSR1, handlerA);

        printf("Process A is sleeping\n");
        while (1)
        {
            pause();
        }
    }

    processB = fork();

    if (processB == 0)
    {
        signal(SIGUSR2, handlerB);

        printf("Process B is sleeping\n");
        while (1)
        {
            pause();
        }
    }

    sleep(2);

    printf("Parent sends SIGUSR1 to Process A\n");
    kill(processA, SIGUSR1);

    sleep(1);

    printf("Parent sends SIGUSR2 to Process B\n");
    kill(processB, SIGUSR2);

    wait(NULL);
    wait(NULL);

    return 0;
}
