#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    int *memory = malloc(sizeof(int) * 5);

    printf("Sizeof memory: %zu\n", sizeof(memory));

    for (int i = 0; i < sizeof(int) * 5; i++)
    {

        *(memory + i) = 10 - i;

        char *p_read_bytes = (char *)memory;

        for (int i = 0; i < 4; i++)
        {
            printf("Data at %p: %02X\n", p_read_bytes + i, *(p_read_bytes + i));
        }

        printf("%d:\t%d\t%p\n", i, *(memory + i), memory + i);
    }

    // Important or else Heap is going to be filled up ;)
    free(memory);

    return 0;
}