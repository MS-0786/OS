#Write a code in C to implement how a process communicates with another process using the pipe function.#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from Parent";
    char buffer[100];

    // Create pipe
    pipe(fd);

    // Create child process
    pid = fork();

    if (pid > 0)
    {
        // Parent process

        close(fd[0]);   // Parent does not read

        // Send message to child
        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);

        wait(NULL);
    }
    else
    {
        // Child process

        close(fd[1]);   // Child does not write

        // Read message from parent
        read(fd[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }

    return 0;
}
