#include <stdio.h>
#include <stdbool.h>
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap_year(int year){
    if (year % 4 != 0){
        return false;
    }
    else if(year % 4 == 0 && (year % 100 != 0 || year % 400 != 0)){
        return true;
    }else
        return true;
}

void add_days_to_date(int *mm, int *dd, int* yy, int days_left_to_add){

    while(days_left_to_add > 0){
        int days_left_in_month = days_in_month[*mm] - *dd;
        if(days_in_month[2] && is_leap_year(*yy) == true){
            days_left_in_month++;
        }
        if(days_left_to_add > days_left_in_month){
            days_left_to_add -= days_left_in_month + 1;
            *dd = 1; //make sure its first day of the month
            if (*mm == 12){ //if we are on december move to next year
                *mm = 1;
                *yy = *yy + 1;
            }
            else *mm = *mm + 1; //otherwise increase month by 1
        }
        else { //if we can fit all the days in the same month
            *dd = *dd + days_left_to_add; //add the days
            days_left_to_add = 0; //reset days left
        }
    }
}

int main(){
    int year;
    int mm, dd, yy, days_left_to_add;
    /*printf("Enter year between 1800 to 10000: ");
    scanf("%i", &year);
    is_leap_year(year);
    if(is_leap_year(year) == true){
      printf("Leap Year");
    }else
      printf("Not Leap Year");*/

    //ADD DAYS TO DATE
    printf("Enter a date between years 1800 and 10000 with the format mm dd yy and provide the numbers of days you want to add to that date: \n");
    scanf ("%i%i%i%i", &mm, &dd, &yy, &days_left_to_add);

    add_days_to_date (&mm, &dd, &yy, days_left_to_add);

    printf("%i %i %i\n", mm, dd, yy);
}