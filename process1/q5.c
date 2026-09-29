5. Write a program with a local variable and a global variable. Initialize both
of them. The program should fork a child process and the child should
increment both the variables by 1. After this operation, both the parent and
the child should print the values of the variable.






  #include <stdio.h>
#include <unistd.h>

int global = 10;

int main()
{
    int local = 20;

    int pid = fork();

    if (pid == 0)
    {
        global++;
        local++;

        printf("Child:\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);
    }
    else
    {
        printf("Parent:\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);
    }

    return 0;
}
