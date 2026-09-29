2. Write a program to print the default message of SIGINT signal and also
prints the user.



  #include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal)
{
    printf("\nSIGINT signal received\n");
    printf("User pressed Ctrl+C\n");
}

int main()
{
    signal(SIGINT, handler);

    printf("Press Ctrl+C\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}
