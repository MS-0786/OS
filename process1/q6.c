6. Implement the assignment no. 5 using vfork for spawning the child.





#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int global = 10;

int main()
{
    int local = 20;

    printf("Before vfork:\n");
    printf("Global = %d\n", global);
    printf("Local = %d\n", local);

    fflush(stdout);

    int pid = vfork();

    if (pid == 0)
    {
        global++;
        local++;

        printf("Child:\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);

        _exit(0);
    }
    else
    {
        printf("Parent:\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);
    }

    return 0;
}

  
