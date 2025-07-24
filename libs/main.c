#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[])
{

    if (DEBUG_MODE == true)
    {
        printf("DEBUGGING MODE: true\n\n");
    }

    process_commands(argc, argv);

    return 0;
}