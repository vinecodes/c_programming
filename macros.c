#include <stdio.h>

#define MAX 20

#define max(x, y) ((x > y) ? x : y)

#define output(s1, s2) printf(#s1 " s2: %s\n", s2)

#define find_min(array, length) ({       \
    typeof(array[0]) min_num = array[0]; \
    for (int i = 0; i < length; i++)     \
        if (array[i] < min_num)          \
            min_num = array[i];          \
    min_num;                             \
})

#define print_thrice(x) ({ \
    int nume = x;          \
    printf("%d\n", nume);  \
    printf("%d\n", nume);  \
    printf("%d\n", nume);  \
})

int g_num = 0;

int increment()
{
    g_num += 1;
    return g_num;
}

int main(int argc, char **argv)
{
    printf("MAX: %d\n", MAX);

    int max_num = max(1, 2);

    int max_num2 = max(max(1, 5), max(2, 3));

    output(max_num, "test1");
    output(max_num2, "test2");

    int num_array[] = {1, 2, 3, 4, 10};
    int num_array_min = find_min(num_array, 5);

    printf("Min Num: %d\n", num_array_min);

    double dbl_array[] = {8.2, 3.3, 2.10, 10.1, 0.2};
    double dbl_array_min = find_min(dbl_array, 5);

    printf("Min Double Num: %lf\n", dbl_array_min);

    int num;
    print_thrice(num = increment());

    return 0;
}