#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    fflush(stdout);
    int rc = fork();
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else { // parent goes down this path (main)
        // wait null or wait 0 means wait for any child
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}
