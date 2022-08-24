#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (rc == 0)
    {
        close(STDOUT_FILENO);
        open("./e7.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        printf("I am child\n");
    }
    else
    {
        printf("I am parent\n");
        // parent goes down this path (original process)
        int wc = wait(NULL);
        assert(wc >= 0);
    }
    return 0;
}
