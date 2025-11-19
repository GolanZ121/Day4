/*------------------------------------------------------
* Filename: time.h
* Description: decleration Time struct of important Time struct util function and constant
* Author: Golan
-------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR (MINUTES_IN_HOUR * SECONDS_IN_MINUTE)

typedef struct {
    int hours; // integer between 0 to 23
    int minutes; // integer between 0 to 59
    int seconds; // integer between 0 to 59
} Time;

void print_time(const Time *t);
int validate_input(int h, int m, int s);
int create_time(Time *t);
void init_time(Time *t);
Time* add_times(const Time *t1, const Time *t2);