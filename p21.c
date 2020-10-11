#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
int sum_of_divisors(int n){
  int sum=0;
  for(int i=1;i<=n/2;i++){
    if(n%i==0)
      sum+=i;
  }
  return sum;
}
int main(){
  int sum=0;
  int tmp=0;;
  for(int i=1;i<10000;i++){
    tmp = sum_of_divisors(i);

    if(sum_of_divisors(tmp)==i && tmp!=i){
      printf("%d %d\n", sum_of_divisors(i),  (tmp));
      sum += i;
    }
  }
  printf("%d", sum);
  return 0;
}
