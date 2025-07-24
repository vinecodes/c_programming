#include <stdio.h>

#define print_str(x) printf("%s", x)
#define DEBUG_MODE 1

// error: initializer element is not a compile-time constant
// int g = 1;
// const int cg = g;

int main(int argc, char *argv[])
{
    const int x = 10;
    const char *c = "Hello World!";
    
    int y = 100;
    const int cy = y;

    printf("Constant: %d\n", x);
    printf("String: %s\n", c);
    printf("String Address: %p\n", &c);

#if DEBUG_MODE == 1
#ifdef print_str
    print_str("Const String Address:\t");
#endif
#endif

    for (int i = 0; i < 3; i++)
    {
        printf("%p\t", &c + i);
        printf("%c\t", *(c + i));
    }

    return 0;
}