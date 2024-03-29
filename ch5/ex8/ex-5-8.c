#include <stdio.h> /* cuz I'm going to have a main function in here */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day);

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int d = day_of_year(2019, 2, 28);
    if(d == -1){
        printf("Error - bad month provided. Must be between 1 & 12. \n");
        return 0;
    }
    if(d == -2){
        printf("Error - bad day provided. Must be within 1 and [28,29,30,31] depending on month.\n");
        return 0;
    }
    int month;
    int day;
    month_day(2019, d, &month, &day);
    if(day == -1){
        printf("Error - bad day provided. Must be between 1 & [365,366] depending on year.\n");
        return 0;
    }
    printf("Month: %d, Day: %d\n", month, day);
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    /* error checking */
    if ((month > 12) || (month < 1)){
        return -1;  /* invalid month */
    }
    if ((day < 1) || (day > daytab[leap][month])){
        return -2;  /* invalid day of month */
    }

    for(i = 1; i < month; i++){
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for(i = 1; yearday > daytab[leap][i]; i++){
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;

    /* Error handling */
    if ((yearday > (365 + leap)) || (yearday < 1)){
        *pday = -1;  /* invalid yearday */
    }
    return;
}