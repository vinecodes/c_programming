#include <stdio.h>
#include <stdlib.h>

typedef char *string;

typedef struct
{
    char name[10];
    int age;
} Student;

struct Point
{
    int x;
    int y;
} p1;

typedef struct Point point_type;

typedef struct
{
    int *array;
} number_data;

int main(int argc, char *argv[])
{

    string name = "Hello, World!";

    printf("%s\n", name);

    Student vineeth = {
        .name = "Vineeth",
        .age = 10};

    printf("Name of the student: %s\n", vineeth.name);
    printf("Age: %d\n", vineeth.age);

    p1.x = 10;
    p1.y = 100;

    printf("Point p1: %d\n", p1.x);
    printf("Point p1: %d\n", p1.y);

    point_type Point_2d = {
        .x = 5,
        .y = 10};

    printf("Point Point_2d.x: %d\n", Point_2d.x);
    printf("Point Point_2d.y: %d\n", Point_2d.y);

    point_type Point_2d_copy = {1, 2};

    // Memory Copy
    Point_2d_copy = p1;

    printf("Point_2d_copy.x: %d\n", Point_2d_copy.x);
    printf("Point_2d_copy.y: %d\n", Point_2d_copy.y);

    number_data num1 = {
        .array = malloc(sizeof(int) * 5)};

    number_data num2 = {
        .array = malloc(sizeof(int) * 5)};

    num1.array[0] = 1;
    num1.array[1] = 2;
    num1.array[2] = 3;
    num1.array[3] = 4;
    num1.array[4] = 5;

    num2.array[0] = 10;
    num2.array[1] = 10;
    num2.array[2] = 10;
    num2.array[3] = 10;
    num2.array[4] = 10;

    printf("num1.array[0]: %d\n", num1.array[0]);
    printf("num1.array[0]: %d\n\n", num1.array[1]);
    printf("num2.array[0]: %d\n", num2.array[0]);
    printf("num2.array[0]: %d\n\n", num2.array[1]);

    num1 = num2;

    printf("num1.array[0]: %d\n", num1.array[0]);
    printf("num1.array[0]: %d\n\n", num1.array[1]);

    num1.array[0] = 7;

    printf("num1.array[0]: %d\n", num1.array[0]);
    printf("num2.array[0]: %d\n", num2.array[0]);
    printf("num2.array[0]: %d\n", num2.array[1]);

    return 0;
}