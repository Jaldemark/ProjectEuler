#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){

  long long sum = 0;
  int check = 0;
  for(int i=2;i<2000000;i++){
    check=0;
    if((i%6)==1||i==2||i==3||(i%6)==5){
      printf("%d\n", i);
      for(int j=2;j<i;j++){
        if(i%j==0){
          check = 1;
          break;
        }
      }
      if(check != 1 ){
        sum += i;
      }
    }
  }
  printf("%lld", sum);
  return 0;
}
