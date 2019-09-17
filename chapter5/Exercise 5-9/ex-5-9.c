#include <stdio.h> /* cuz I'm going to have a main function in here */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int *month, int *day);

/* month_day: set month, day from day of year */
void month_day(int *year, int *yearday, int *pmonth, int *pday);

// Driver code
int main()
{
    /* TEST DATA */
    int day = 31;
    int month = 3;
    int year = 2017;

    int yearday = day_of_year(year, &month, &day);
    if(yearday == -1){
        printf("Error - bad month provided. Must be between 1 & 12. \n");
        return 0;
    }
    if(yearday == -2){
        printf("Error - bad day provided. Must be within 1 and [28,29,30,31] depending on month.\n");
        return 0;
    }
    month_day(&year, &yearday, &month, &day);
    if(day == -1){
        printf("Error - bad day provided. Must be between 1 & [365,366] depending on year.\n");
        return 0;
    }
    printf("Month: %d, Day: %d\n", month, day);
    return 0;
}

int day_of_year(int year, int *month, int *day)
{
    int i, leap;
    int *pday = day;
    int *pmonth = month;
    char (*pdaytab)[1] = daytab;

    leap = ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0);
    pdaytab += (leap*13);
    /* error checking */
    if ((*pmonth > 12) || (*pmonth < 1)){
        return -1;  /* invalid month */
    }
    if ((*pday < 1) || (*pday > *pdaytab[*pmonth])){
        return -2;  /* invalid day of month */
    }
    for(i = 1; i < *pmonth; i++){
        *pday += *pdaytab[i];
    }
    return *pday;
}

void month_day(int *year, int *yearday, int *pmonth, int *pday)
{
    int i, leap;
    int *pyear = year;
    int *pyearday = yearday;
    char (*pdaytab)[1] = daytab;

    leap = ((*pyear%4 == 0) && (*pyear%100 != 0)) || *pyear%400 == 0;
    pdaytab += (leap*13);

    for(i = 1; *pyearday > daytab[leap][i]; i++){
        *pyearday -= *pdaytab[i];
    }
    *pmonth = i;
    *pday = *pyearday;


    /* Error handling */
    if ((*pyearday > (365 + leap)) || (*pyearday < 1)){
        *pday = -1;  /* invalid yearday */
    }
    return;
}