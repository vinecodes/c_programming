#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buffer[1];

    size_t file_read_size = fread(buffer, sizeof(char), 10000, file);
    buffer[file_read_size] = '\0';

    printf("File Read: %zu\n", file_read_size);

    printf("File Data: %s\n", buffer);

    return EXIT_SUCCESS;
}