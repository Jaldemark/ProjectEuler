#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
int main(){
  int grid = 20;
  long counter =1;
  for(int i=0;i<grid;i++){
    counter = counter*((20*2)-i);
    counter = counter/(i+1);
  }
  printf("counter: %ld", counter);
  return 0;
}
