#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>

static inline int is_odd(int x) { return x & 1; }

int main(){
  clock_t start, end;
  double cpu_time_used;
  long counter=1;
  long highest[2];
  highest[0]=0;
  long number;
  start = clock();
  for(long i=4;i<1000000;i++){
    number = i;
    while(number!=1){
      number = (is_odd(number) ? number*3+1 : number/2);
      counter++;
    }
    if(highest[0]<counter){
      highest[0] = counter;
      highest[1] = i;
    }
    counter =1;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("highest: %ld\n", highest[0]);
  printf("number: %ld\n", highest[1]);
  printf("time used: %.4f seconds", cpu_time_used);
  return 0;
}//525
