#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
    #define IS_POSIX 1
#else
    #define IS_POSIX 0
#endif


int main (int argv, char **argc)
{
    if (IS_POSIX == 1) {
        puts("Path info by use environment variable PWD:");
        printf("\tWorkdir: %s\n", getenv("PWD"));
        printf("\tFilepath: %s/%s\n", getenv("PWD"), __FILE__);
    }
    return 0;
}
