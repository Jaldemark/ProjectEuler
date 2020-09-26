#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int num =1;
  bool b;
  while(true){
    b=true;
    for(int i=1;i<=20;i++){
      if(num%i!=0){
        b=false;
        break;
      }
    }
    if(b)
      break;
    else
      num++;
  }
  printf("%d", num);
  return 0;
}
