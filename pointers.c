#include <stdio.h>

struct Car
{
    int age;
    int length;
};

void increase_default_car_params(struct Car *pCar, char *pResult);

int main(int argc, char **argv)
{
    struct Car seltos = {1, 20};

    char result = 'a';
    char *pResult = &result;

    increase_default_car_params(&seltos, &result);

    printf("%d\n", seltos.age);
    printf("%d\n", seltos.length);

    printf("Sending back result: %c\n", result);

    return 0;
}

void increase_default_car_params(struct Car *pCar, char *pResult)
{
    // struct member access
    pCar->age *= 10;
    pCar->length *= 2;

    printf("Result_increase_default_car_params: %c\n", *pResult);

    *pResult = 's';
}

