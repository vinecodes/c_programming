#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "Pokiri";
    char *str_to_match = "kiri";

    size_t str1_len = strlen(str1);

    char *psubstr = strpbrk(str1, str_to_match);

    for (size_t i = 0; i < str1_len; i++)
    {
        printf("%c: \t%p\n", str1[i], &str1[i]);
    }

    if (psubstr != NULL)
    {
        printf("\n%s\n", psubstr);
        printf("%p\n", psubstr);
    }

    return 0;
}