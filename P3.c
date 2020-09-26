#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  long long largest =1;
  long long num = 600851475143;
  long long largest_possible=1;
  long long divided;
  bool b = true;
  for(int i=2;i<num/largest_possible;i++){
    divided = (num/i);
    b = true;
    if(divided*i==num){
      for(int j=2;j<divided;j++){
        if(divided%j==0){
          b=false;
          break;
        }
      }
      if(b){
        largest_possible = largest_possible*divided;
        largest = divided;
      }
    }
  }
  printf("%lld is largest", largest);
  return 0;
}
