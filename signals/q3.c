3. Write a program for a process which cannot be killed by pressing Ctrl
+ c and again restore the default status of it. (Print necessary messages
where required).



  #include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    printf("SIGINT is now ignored.\n");
    printf("Press Ctrl+C. Nothing will happen.\n");

    signal(SIGINT, SIG_IGN);

    sleep(10);

    printf("\nRestoring default SIGINT behavior.\n");
    printf("Press Ctrl+C now.\n");

    signal(SIGINT, SIG_DFL);

    while (1)
    {
        sleep(1);
    }

    return 0;
}
