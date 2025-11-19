/*------------------------------------------------------
* Filename: time.c
* Description: implmentation of important Time struct util function
* Author: Golan
-------------------------------------------------------*/

#include "time.h"


/*------------------------------------------------------
* Function Name - print_time
*
* Function Purpose - to print a Time struct in a formmated way
*
* Parameters –  [IN t - a pointer to a Time struct] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void print_time(const Time *t){
    printf("Time: %02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}

/*------------------------------------------------------
* Function Name - validate_time_input 
*
* Function Purpose - to make sure the hours, minutes, secodns are valid values
*
* Parameters –  [IN h - 23, 12, -2334] 
*               [IN m - 45, 43, 0] 
*               [IN s - 15, 23, 0] 
*
* Return Values - 0 if time is invalid h = 26 or m = -2, return 1 if valid
*
* Author - Golan Ziv
-------------------------------------------------------*/
int validate_input(int h, int m, int s){
    if(h < 0 || h >= HOURS_IN_DAY) return 0;
    if(m < 0 || m >= MINUTES_IN_HOUR) return 0;
    if(s < 0 || s >= SECONDS_IN_MINUTE) return 0;

    return 1; // input is good
}

/*------------------------------------------------------
* Function Name - create_time
*
* Function Purpose - to fill a Time struct by taking user input, ensuring validity
*
* Parameters –  [IN t - a pointer to a Time struct] 
*
* Return Values - 1 if input is invalid, 0 for success
*
* Author - Golan Ziv
-------------------------------------------------------*/
int create_time(Time *t){
    int h, m, s;
    
    printf("Enter data for dynamic struct in this format: 'hh:mm:ss' \n");
    if(scanf(" %d:%d:%d", &h, &m, &s) == 0 || !validate_input(h,m,s)){
        return 1;
    }
    
    t->hours = h;
    t->minutes = m;
    t->seconds = s;
    return 0;
}

/*------------------------------------------------------
* Function Name - init_time 
*
* Function Purpose - init Time struct with 0s
*
* Parameters –  [IN t1 - pointer to Time struct] 
*
* Return Values - void
*
* Author - Golan Ziv
-------------------------------------------------------*/
void init_time(Time *t){
    t->hours = 0;
    t->minutes = 0;
    t->seconds = 0;
}

/*------------------------------------------------------
* Function Name - add_times 
*
* Function Purpose - add to Time struct together and return a pointer to the new struct
*
* Parameters –  [IN t1 - pointer to Time struct] 
*               [IN t2 - pointer to Time struct] 
*
* Return Values - pointer to new Time struct
*
* Author - Golan Ziv
-------------------------------------------------------*/
Time* add_times(const Time *t1, const Time *t2){
    Time *result;
    int tot_secs1, tot_secs2, total;
    
    result = (Time *) malloc(sizeof(Time));

    // Here I calculate the totoal sconds in each time struct.
    // a second is 1 second
    // a minute is 60 seconds
    // an hour is 60 minutes which is 3600 seconds
    tot_secs1 = t1->seconds + t1->minutes*SECONDS_IN_MINUTE + t1->hours*SECONDS_IN_HOUR;
    tot_secs2 = t2->seconds + t2->minutes*SECONDS_IN_MINUTE + t2->hours*SECONDS_IN_HOUR;

    total = tot_secs1 + tot_secs2;

    // Here, to convert the seconds to hours, minutes and seconds,
    // I do the following:
    // to get hours, i divide by SECONDS_IN_HOUR (to keep it in 24 i use mod24)
    // to get minutes, i get the mod of total seconds by SECONDS_IN_HOUR
    //   and divide that by SECONDS_IN_MINUTE
    // to get seconds, i get the mod of total seconds by SECONDS_IN_MINUTE
    result->hours = total / SECONDS_IN_HOUR % HOURS_IN_DAY;
    result->minutes = (total % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    result->seconds = total % SECONDS_IN_MINUTE;

    return result;
}