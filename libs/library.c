#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool DEBUG_MODE = false;

// Makes it available only in the code file where it is defined even though it is declared as extern in the library.h header file.
// static bool DEBUG_MODE = false;

typedef enum
{
    OPEN,
    EXIT,
    NONE
} Commands;

Commands convert_command(char *arg)
{
    if (strcmp(arg, "OPEN") == 0)
    {

        if (DEBUG_MODE == true)
        {
            printf("Reaching: OPEN condition\n");
        }

        return OPEN;
    }
    else if (strcmp(arg, "EXIT") == 0)
    {

        if (DEBUG_MODE == true)
        {
            printf("Reaching: EXIT condition\n");
        }

        return EXIT;
    }
    else
        return NONE;
}

void process_commands(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {

        printf("Command Received: %s\n", argv[i]);

        Commands command = convert_command(argv[i]);

        printf("Command ID: %d\n\n", command);
    }
}