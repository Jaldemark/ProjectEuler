#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
/*Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n.
 For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 n 	Relatively Prime 	φ(n) 	n/φ(n)
 2 	1 	1 	2
 3 	1,2 	2 	1.5
 4 	1,3 	2 	2
 5 	1,2,3,4 	4 	1.25
 6 	1,5 	2 	3
 7 	1,2,3,4,5,6 	6 	1.1666...
 8 	1,3,5,7 	4 	2
 9 	1,2,4,5,7,8 	6 	1.5
 10 	1,3,7,9 	4 	2.5
 It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
 Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
 */
float phi(int n){
  int result = n;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      while(n%i==0)
        n/=i;
      result-=result/i;
    }
  }
  if(n>1)
    result-=result/n;
  return result;
}
int main(){
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  int upper_limit=1000000;
  float highest=0;
  int n;
  double p;
  for(float i=2;i<=upper_limit;i+=2){
    p=i/phi(i);
    if(highest<=p){
      highest = p;
      n=i;
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("cpu time used: %.2f seconds\n", cpu_time_used);
  printf("%.f %d", highest,n);
  return 0;
}
