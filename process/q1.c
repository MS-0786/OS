1. Write a program that creates three child processes. The first child
process executes the command “who”, the second child process
executes the command “ls” passing it the parameter “–al” using
execlp(..) C function and the third child process executes the command
“date” with path ”/bin/date” in execl() C function. The parent process
waits for all the child processes to finish and prints the termination status
of the child. (C Library unistd.h contains all exec.... Functions)






  #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid1, pid2, pid3;
    int status;

    // First child
    pid1 = fork();

    if (pid1 == 0)
    {
        printf("Child 1 executing who:\n");

        execlp("who", "who", (char *)NULL);

        perror("execlp failed");
        exit(1);
    }

    // Second child
    pid2 = fork();

    if (pid2 == 0)
    {
        printf("Child 2 executing ls -al:\n");

        execlp("ls", "ls", "-al", (char *)NULL);

        perror("execlp failed");
        exit(1);
    }

    // Third child
    pid3 = fork();

    if (pid3 == 0)
    {
        printf("Child 3 executing date:\n");

        execl("/bin/date", "date", (char *)NULL);

        perror("execl failed");
        exit(1);
    }

    // Parent waits for all three children
    waitpid(pid1, &status, 0);
    printf("Child 1 terminated. Status = %d\n", status);

    waitpid(pid2, &status, 0);
    printf("Child 2 terminated. Status = %d\n", status);

    waitpid(pid3, &status, 0);
    printf("Child 3 terminated. Status = %d\n", status);

    printf("Parent process finished.\n");

    return 0;
}

