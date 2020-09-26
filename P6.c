#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int sum_of_squares = 0; //338350
  int square_of_sum = 0; // 25502500
  int diff;
  for(int i=1;i<=100;i++){
    sum_of_squares += pow(i,2);
    square_of_sum += i;
  }
  square_of_sum = pow(square_of_sum,2);
  diff = square_of_sum - sum_of_squares;
  printf("%d\n", diff);
}
