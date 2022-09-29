#define _GNU_SOURCE
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Expecting 2 arguments, got %d\n", argc - 1);
        return 1;
    }

    int pages = atoi(argv[1]);
    int trials = atoi(argv[2]);

    int PAGESIZE = getpagesize();
    int jump = PAGESIZE / sizeof(int);

    int a[pages * jump];
    for (int i = 0; i < pages * jump; i++)
    {
        a[i] = 0;
    }

    // Pin thread to run on cpu 0 to use the same tlb cache throughout the whole run.
    pthread_t thread;
    thread = pthread_self();
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int ret = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (ret != 0)
    {
        printf("pthread_setaffinity_np: %d\n", ret);
        return 1;
    }

    struct timeval t1;
    gettimeofday(&t1, NULL);
    long int start = t1.tv_sec * 100000 + t1.tv_usec;

    for (int i = 0; i < trials; i++)
    {
        for (int j = 0; j < pages * jump; j += jump)
        {
            a[j] += 1;
        }
    }

    struct timeval t2;
    gettimeofday(&t2, NULL);
    long int end = t2.tv_sec * 100000 + t2.tv_usec;

    printf("access time in ns: %ld\n", (end - start) * 1000 / trials / pages);

    // Ensure that the compile does not omit the above statements for value
    // not used.
    FILE *debug;
    debug = fopen("/dev/null", "w");
    for (int i = 0; i < pages * jump; i++)
    {
        fprintf(debug, "%d", a[i]);
    }

    return 0;
}