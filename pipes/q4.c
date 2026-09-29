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
    int pipe1[2];
    int pipe2[2];

    pid_t pid;

    int number;
    int result;
    int sum;

    // Create two pipes
    pipe(pipe1);
    pipe(pipe2);

    // Create child
    pid = fork();

    if (pid > 0)
    {
        // Parent

        // Parent writes to pipe1
        close(pipe1[0]);

        // Parent reads from pipe2
        close(pipe2[1]);

        while (1)
        {
            printf("Enter a number: ");
            scanf("%d", &number);

            // Send number to child
            write(pipe1[1], &number, sizeof(number));

            if (number == 0)
            {
                break;
            }

            // Receive result from child
            read(pipe2[0], &result, sizeof(result));

            printf("Sum = %d\n", result);
        }

        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL);
    }
    else
    {
        // Child

        // Child reads from pipe1
        close(pipe1[1]);

        // Child writes to pipe2
        close(pipe2[0]);

        while (1)
        {
            // Receive number
            read(pipe1[0], &number, sizeof(number));

            if (number == 0)
            {
                break;
            }

            // Calculate sum
            sum = 0;

            for (int i = 1; i <= number; i++)
            {
                sum = sum + i;
            }

            // Send result to parent
            write(pipe2[1], &sum, sizeof(sum));
        }

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
