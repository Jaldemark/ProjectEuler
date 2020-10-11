#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

int is_prime(int n){
  if(n==1)
    return 0;
  if(n==2||n==3||n==5)
    return 1;
  if((n%2==0)||n%3==0||n%5==0)
    return 0;
  for(int i=3;i<=sqrt(n);i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}

int left2right(int n){
  int length = floor(log10(abs(n))) + 1;
  int p;
  for(int i=1;i<length;i++){
    p=pow(10,length-i);
    if(!is_prime(n%p))
      return 0;
  }
  return 1;
}
/*n=1234
n=123
n=12
n=1*/
int right2left(int n){
  int length = floor(log10(abs(n))) + 1;
  for(int i=0;i<length;i++){
    if(!is_prime(n))
      return 0;
    n/=10;
  }
  return 1;
}
int main(){
  int prime_counter =0;//max 11
  int sum=0;
  int i=9;
  left2right(1234);
  right2left(1234);
  while(prime_counter!=11){
    if(left2right(i)&&right2left(i)){
      sum+=i;
      prime_counter++;
    }
    i+=2;
  }
  printf("%d", sum);
  return 0;
}
