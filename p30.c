#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 999999 = 6*9^5= 354294
*/
int main(){
  clock_t start, end;
  double cpu_time_used;
  int sum_tmp=0;
  int sum_total=0;
  int length, tmp;
  start = clock();
  for(int i=1000;i<354294;i++){
    length = floor(log10(abs(i))) + 1;
    tmp=i;
    for(int j=0;j<length;j++){
      sum_tmp+=pow(tmp%10, 5);
      tmp = tmp/10;
    }
    if(sum_tmp==i){
      sum_total+=sum_tmp;
    }
    sum_tmp=0;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%d\n", sum_total);
  printf("cpu time used: %.2f seconds", cpu_time_used);
  return 0;
}
