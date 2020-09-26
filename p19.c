#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
struct Day{
  char* day;
  struct Day* next;
};
struct Month{
  int days;
  char* month;
  struct Month* next;
};

int main(){
  struct Day* monday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* tuesday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* wednesday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* thursday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* friday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* saturday = (struct Day*)malloc(sizeof(struct Day));
  struct Day* sunday = (struct Day*)malloc(sizeof(struct Day));
  monday->next = tuesday;
  tuesday->next = wednesday;
  wednesday->next = thursday;
  thursday->next = friday;
  friday->next = saturday;
  saturday->next = sunday;
  sunday->next = monday;
  struct Month* january = (struct Month*)malloc(sizeof(struct Month));
  struct Month* february = (struct Month*)malloc(sizeof(struct Month));
  struct Month* march = (struct Month*)malloc(sizeof(struct Month));
  struct Month* april = (struct Month*)malloc(sizeof(struct Month));
  struct Month* may = (struct Month*)malloc(sizeof(struct Month));
  struct Month* june = (struct Month*)malloc(sizeof(struct Month));
  struct Month* july = (struct Month*)malloc(sizeof(struct Month));
  struct Month* august = (struct Month*)malloc(sizeof(struct Month));
  struct Month* september = (struct Month*)malloc(sizeof(struct Month));
  struct Month* october = (struct Month*)malloc(sizeof(struct Month));
  struct Month* november = (struct Month*)malloc(sizeof(struct Month));
  struct Month* december = (struct Month*)malloc(sizeof(struct Month));
  january->days=31;
  february->days=28;
  march->days=31;
  april->days=30;
  may->days=31;
  june->days=30;
  july->days=31;
  august->days=31;
  september->days=30;
  october->days=31;
  november->days=30;
  december->days=31;
  january->next=february;
  february->next=march;
  march->next=april;
  april->next=may;
  may->next=june;
  june->next=july;
  july->next=august;
  august->next=september;
  september->next=october;
  october->next=november;
  november->next=december;
  december->next=january;
  int year = 1900;
  int sunday_counter = 0;
  int day_counter = 1;
  int month_counter = 1;
  struct Month* current_month = (struct Month*)malloc(sizeof(struct Month));
  current_month = january;
  struct Day* current_day = (struct Day*)malloc(sizeof(struct Day));
  current_day = monday;
  while(year!=2001){
    if(year%4==0){
      february->days=29;
    }
    else{
      february->days=28;
    }
    while(month_counter<=12){
      while(day_counter <= current_month->days){
        if(day_counter==1 && current_day==sunday && year>1900){
          sunday_counter++;
        }
        current_day=current_day->next;
        day_counter++;
      }
      day_counter=1;
      current_month=current_month->next;
      month_counter++;
    }
    month_counter=1;
    year++;
  }
  printf("times the first day of the month is sunday: %d", sunday_counter);
  return 0;
}
