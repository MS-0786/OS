2. Write a program to create a process which will run as a background
process for fifty seconds and at the time of execution it will print the
system information.





  #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main()
{
    int pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        struct utsname systemInfo;

        printf("Background process started.\n");
        printf("PID = %d\n", getpid());

        if (uname(&systemInfo) == 0)
        {
            printf("System information:\n");
            printf("System: %s\n", systemInfo.sysname);
            printf("Node: %s\n", systemInfo.nodename);
            printf("Release: %s\n", systemInfo.release);
            printf("Machine: %s\n", systemInfo.machine);
        }

        sleep(50);

        printf("Background process finished.\n");

        exit(0);
    }

    printf("Parent process finished.\n");

    return 0;
}
  
