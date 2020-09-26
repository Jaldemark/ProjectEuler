#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int term = 1;
  int new_term =0;
  int prev_term = 0;
  int sum = 0;
  while((term + prev_term)<4000000){
    new_term = term + prev_term;
    if(new_term%2==0){
      sum += new_term;
    }
    prev_term = term;
    term = new_term;
  }
  printf("%d", sum);
  return 0;
}
