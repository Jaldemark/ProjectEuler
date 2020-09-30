#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
int main(){
  int sum =0;
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  for(int i=0;i<1000;i++){
    if(i%3==0 || i%5==0){
      sum +=i;
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("cpu time used: %.10f seconds\n", cpu_time_used);
  printf("%d", sum);
  return 0;
}
