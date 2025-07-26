#include <stdio.h>

enum DaysOfWeek
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday
};

typedef enum PowerStates
{
    ON,
    OFF
} Button_PowerStates;

void flip_btn_powerstate(Button_PowerStates *);
void print_btn_powerstate(Button_PowerStates);

int main(int argc, char *argv[])
{

    enum DaysOfWeek today = Monday;
    enum DaysOfWeek tomorrow = Friday;

    printf("Day of Week: %d\n", today);
    printf("Day of Week: %d\n", tomorrow);

    printf("Sizeof today: %zu\n", sizeof(enum DaysOfWeek));

    Button_PowerStates btn_power = ON;
    Button_PowerStates *p_btn_power = &btn_power;

    print_btn_powerstate(btn_power); // ON

    flip_btn_powerstate(p_btn_power); // OFF
    print_btn_powerstate(btn_power);  // OFF

    flip_btn_powerstate(p_btn_power); // ON
    flip_btn_powerstate(p_btn_power); // OFF

    print_btn_powerstate(btn_power); // OFF

    return 0;
}

void flip_btn_powerstate(Button_PowerStates *p_btn_powerstate)
{
    *p_btn_powerstate = (*p_btn_powerstate == ON) ? OFF : ON;
}

void print_btn_powerstate(Button_PowerStates btn_powerstate)
{
    if (btn_powerstate == ON)
        printf("ON\n");
    else
        printf("OFF\n");
}