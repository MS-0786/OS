3. Write a program that creates two child processes. Each of the child
process prints numbers from 1 to 10. Each time a child prints a number
it also prints its own PID and parent PID. The parent waits for both of its
child to finish execution and prints “Good Bye” before exiting.






  #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid1, pid2;

    // Create first child
    pid1 = fork();

    if (pid1 == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("Child 1: Number = %d, PID = %d, PPID = %d\n",
                   i, getpid(), getppid());

            sleep(1);
        }

        exit(0);
    }

    // Create second child
    pid2 = fork();

    if (pid2 == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("Child 2: Number = %d, PID = %d, PPID = %d\n",
                   i, getpid(), getppid());

            sleep(1);
        }

        exit(0);
    }

    // Parent waits for both children
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Good Bye\n");

    return 0;
}
  
