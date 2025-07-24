#include <stdio.h>

#define BUFFER_SIZE 100
#define PLATFORM_CODE 1
#define VERSION_CODE 'a'

#define print(x) printf("%s\n", x)
#define print_char(fmt, x) printf(fmt, x)

int main(int argc, char **argv)
{

#if PLATFORM_CODE == 0
    print("PLATFORM_CODE is Linux");
#elif PLATFORM_CODE == 1
    print("PLATFORM_CODE is macOS");
#elif PLATFORM_CODE == 2
    print("PLATFORM_CODE is Free BSD");
#else
    print("PLATFORM_CODE is unknown!");
#endif

#if CX
    printf("CX is not defined!");
#endif

#if VERSION_CODE == 'a' || 1
#ifdef print_char
    print_char("VERSION_CODE is %c\n", VERSION_CODE);
#endif
#endif

#if 0
    print("Hello, false!");
#else
    print("Hello, true!");
#endif

#if - 1
    print("Hello, true!");
#else
    print("Hello, false!");
#endif

#if 10
    print("Hello, true!");
#else
    print("Hello, false!");
#endif

    return 0;
}