Write a code in C to implement how a process communicates with another process using the popen function.#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[100];

    // Open a pipe with the ls command
    fp = popen("ls", "r");

    if (fp == NULL)
    {
        printf("Pipe could not be opened\n");
        return 1;
    }

    // Read output of ls
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    // Close pipe
    pclose(fp);

    return 0;
}
