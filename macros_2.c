#include <stdio.h>

#define DEBUG_MODE

#undef DEBUG_MODE

int main(int argc, char **argv)
{

#ifdef DEBUG_MODE
    printf("Hello World! I am in DEBUG_MODE currently.\n");
#else
    printf("Hello mowa! I am not in DEBUG_MODE currently from the #else directive.\n");
#endif

#ifndef DEBUG_MODE
    printf("Hello mowa! I am not in DEBUG_MODE currently.\n");
#endif

#if defined(DEBUG_MODE)
    printf("Testing DEBUG_MODE using defined(...) directive.\n");
#endif

#if !defined(DEBUG_MODE)
    printf("Testing DEBUG_MODE using !defined(...) directive.\n");
#endif

    return 0;
}