#include <stdio.h>
#include <string.h>

struct Address
{
    char address1[30];
    int pincode;
};

typedef struct
{
    char name[20];
    struct Address address;
} Company;

typedef struct
{
    char color[20];
    char name[20];
    int id;

    Company *company;

} Car;

// Self Referential Struct
struct Booklet
{
    char name[20];

    int no_of_pages;

    Car car;

    struct Booklet *booklet;
};

int main(int argc, char *argv[])
{

    Company kia = {.name = "Kia", .address = {.address1 = "Anantapur, AP", .pincode = 101010}};

    // Seltos
    Car seltos = {};

    strcpy(seltos.color, "Graphite <3");
    strcpy(seltos.name, "Kia Seltos X-Line");

    seltos.id = 10;

    seltos.company = &kia;

    printf("%s, %s, %d\n", seltos.color, seltos.name, seltos.id);
    printf("%s, %s, %d\n", seltos.company->name, seltos.company->address.address1, seltos.company->address.pincode);

    // Sonet
    Car sonet = {};

    strcpy(sonet.color, "Black");
    strcpy(sonet.name, "Kia Sonet");

    sonet.id = 11;

    sonet.company = &kia;

    // Syros
    Car syros = {};

    strcpy(syros.color, "Blue");
    strcpy(syros.name, "Kia Syros");

    syros.id = 12;

    syros.company = &kia;

    // Booklet - Self referential struct

    struct Booklet book_seltos = {};

    strcpy(book_seltos.name, "Kia Seltos Book");
    book_seltos.no_of_pages = 10;

    book_seltos.car = seltos;

    struct Booklet book_sonet = {};

    strcpy(book_sonet.name, "Kia Sonet Book");
    book_sonet.no_of_pages = 5;

    book_sonet.car = sonet;

    struct Booklet book_syros = {};

    strcpy(book_syros.name, "Kia Syros Book");
    book_syros.no_of_pages = 30;

    book_syros.car = syros;

    book_seltos.booklet = &book_sonet;
    book_sonet.booklet = &book_syros;
    book_syros.booklet = NULL;

    struct Booklet *bookreader = &book_seltos;

    while (bookreader != NULL)
    {

        printf("\n\nBooklet\n--------------------\n");
        printf("Name of the Booklet: %s,\nNo. Of Pages: %d\n", bookreader->name, bookreader->no_of_pages);

        printf("\nCar\n--------------------\n");
        printf("%s, %s, %d\n", bookreader->car.color, bookreader->car.name, bookreader->car.id);
        printf("%s, %s, %d\n", bookreader->car.company->name, bookreader->car.company->address.address1, bookreader->car.company->address.pincode);

        bookreader = bookreader->booklet;
    }

    return 0;
}