#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


int main(){

  int tmp;
  for(int i=11;i<30;i++){
    tmp =i;
    for(int j=0;j<2;j++){

      tmp /=tmp;
      printf("%d\n", tmp);
    }
  }
  return 0;
}
