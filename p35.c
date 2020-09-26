#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

//rotates to the right, 1234 becomes 4123
int rotate(int n, int length){
  int tmp;
  int * arr = (int *) malloc(length * sizeof(int)), * curr = arr;
  int j=length-1;
  int new_int=0;
  while(n != 0){
    curr[j]= n % 10;
    n /= 10;
    j--;
  }
  tmp = arr[length-1];
  for(int i=length-1;i>=0;i--){
    if((i)==0){
      arr[i]=tmp;
      new_int+=arr[i]*pow(10,length-1-i);
    }
    else{
      arr[i]=arr[i-1];
      new_int+=arr[i]*pow(10,length-1-i);
    }
  }
  free(arr);
  return new_int;
}
int is_prime(int n){
  int prime =1;
  if((n%5==0&&n!=5)||n%2==0)
    return 0;
  for(int i=3;i<=n/2;i+=2){
    if(n%i==0){
      prime=0;
      break;
    }
  }
  return prime;
}
int main(){
  int circular_primes =1; //count 2'
  int length;
  int tmp;
  int prime=1;
  for(int i=3;i<1000000;i+=2){
    length = floor(log10(abs(i))) + 1;
    if(is_prime(i)){
      tmp = rotate(i, length);
      for(int k=0;k<length-1;k++){
        if(!is_prime(tmp)){
          prime=0;
          break;
        }
        tmp = rotate(tmp, length);
      }
      if(prime){
        circular_primes++;
      }
      prime=1;
    }
  }
  printf("%d",circular_primes);
  return 0;
}
