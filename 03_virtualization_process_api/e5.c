#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <unistd.h>

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
        int wc = wait(NULL);
        printf("I am child with wait returning %d\n", wc);
        assert(wc >= 0);
    }
    else
    {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("I am parent with wait returning %d\n", wc);
        assert(wc >= 0);
    }
    return 0;
}
