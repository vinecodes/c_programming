#include <stdio.h>
#include <limits.h>

#if INT_MAX < 2147483648
#error INT_MAX is not large enough
#endif

int main(int argc, char **argv)
{

    printf("INT_MAX: %d\n", INT_MAX);

    return 0;
}