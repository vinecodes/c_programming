#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 1;    // x000001
    int *pX = &x; // pX = x000001
    int **ppX = &pX;

    printf("%p\n", &x);

    printf("%p\n", *(&pX));

    printf("%d\n", **(&pX));

    printf("%p\n", *ppX);

    return 0;
}

/*

int x = 1;  // x000001
int *pX = &x; // pX = x000001
int **ppX = &pX;


// int *(&pX) = x000001

int **pppX = &ppX;

// int *(&ppX) = x000001

printf("%p\n", *ppX);

int x = 10;
int *p1 = &x; // Address of x is stored in p1

int **p2 = &p1 //
// *p2 = &p1 = &x
// **p2 = *(&p1) = *(Address of p1) = 42



*/