#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *env_str = getenv("C_LOG");

    if (env_str == NULL)
    {
        fprintf(stderr, "Environment variable C_LOG is not set.\n");
        return EXIT_FAILURE;
    }

    printf("C_LOG: %s\n", env_str);
    return EXIT_SUCCESS;
}