#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     int *ptr = NULL;
//     printf("%d", *ptr);
//     return 0;
// }

// int main()
// {
//     char *str;
//     str = (char *)malloc(15);
//     return 0;
// }

// int main()
// {
//     int *data;
//     data = (int *)malloc(100 * sizeof(int));
//     data[100] = 0;
//     free(data);
//     return 0;
// }

// int main()
// {
//     int *data;
//     data = (int *)malloc(100 * sizeof(int));
//     free(data);
//     printf("%d\n", data[0]);
//     return 0;
// }

int main()
{
    int *data;
    data = (int *)malloc(100 * sizeof(int));
    free(data[1]);
    return 0;
}
