3. Write a program that creates a one-way pipe between a parent and child
process. The parent process gets a string from standard input and sends
the string to the child. The child prints the reverse of the string. Both
parent and child terminates when the string “quit” is input.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void reverse(char str[])
{
    int i, j;
    char temp;

    j = strlen(str) - 1;

    for (i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    int fd[2];
    pid_t pid;

    char message[100];
    char buffer[100];

    // Create pipe
    pipe(fd);

    // Create child
    pid = fork();

    if (pid > 0)
    {
        // Parent

        close(fd[0]);   // Parent only writes

        while (1)
        {
            printf("Enter a string: ");
            scanf("%s", message);

            // Send string to child
            write(fd[1], message, strlen(message) + 1);

            if (strcmp(message, "quit") == 0)
            {
                break;
            }
        }

        close(fd[1]);

        wait(NULL);
    }
    else
    {
        // Child

        close(fd[1]);   // Child only reads

        while (1)
        {
            // Receive string
            read(fd[0], buffer, sizeof(buffer));

            if (strcmp(buffer, "quit") == 0)
            {
                break;
            }

            reverse(buffer);

            printf("Reversed string: %s\n", buffer);
        }

        close(fd[0]);
    }

    return 0;
}
