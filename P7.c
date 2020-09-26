#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int prime_counter=0;
  int counter =2;
  int primes;
  int check = 0;
  while(prime_counter!=10001){
    check = 0;
    for(int i=2; i<counter;i++){
      if(counter%i==0){
        check = 1;
        break;
      }
    }
    if(check != 1){
      primes=counter;
      prime_counter++;
    }
    counter++;
    printf("%d\n", prime_counter);
  }
  printf("%d", primes);
}
