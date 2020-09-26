#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>

int main(){
  int a[302]={0};
  int leftover = 0;
  int highest_bit, sum;
  a[301]=1;
  for(int i=0;i<1000;i++){
    for(int j=301;j>=0;j--){
      if(a[j]!=0){
        highest_bit = j;
        if((a[j]*2+leftover)>9){
          a[j]=(a[j]*2+leftover)%10;
          leftover=1;
        }
        else{
          a[j]=a[j]*2+leftover;
          leftover=0;
        }
      }
      else{
        a[j]=leftover;
        leftover=0;
      }
    }
    if(leftover){
      a[highest_bit-1]++;
    }
    leftover=0;
  }
  for(int k=0;k<302;k++){
    sum += a[k];
  }
  printf("%d", sum);
  return 0;
}
