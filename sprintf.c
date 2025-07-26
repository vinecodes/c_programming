#include <stdio.h>
#include <string.h>

// sprintf stores data in a character array
// The format specifier is used to control the output format

int main(int argc, char *arghv[])
{
    char str_pi[5];
    double pi = 3.14159265358979323846;
    sprintf(str_pi, "%.10f", pi);
    printf("Pi to two decimal places: %s\n", str_pi);

    size_t str_pi_length = strlen(str_pi);

    for (int i = 0; i < 20; i++)
    {

        if (str_pi[i] == '\0')
        {
            printf("%d: NULL\n", i);
            continue;
        }

        printf("%d: %c\n", i, str_pi[i]);
    }

    // snprintf
    char str_snpi[10];
    snprintf(str_snpi, sizeof(str_snpi), "%.10f", pi);
    printf("\nPi to ten decimal places: %s\n", str_snpi);

    return 0;
}