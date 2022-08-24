#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    printf("seconds : %ld  micro seconds : %ld\n", current_time.tv_sec, current_time.tv_usec);

    // 1M
    // With syscall:    0.2s
    // Without syscall: 0.001s
    for (int i = 0; i < 1000000; i++)
    {
        // read(0, NULL, 0);
    }

    gettimeofday(&current_time, NULL);
    printf("seconds : %ld  micro seconds : %ld\n", current_time.tv_sec, current_time.tv_usec);
}
