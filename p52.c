#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
/*

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/
int compare(int n1, int n2){//not my proudest function
  int length1 = floor(log10(abs(n1))) + 1;
  int length2 = floor(log10(abs(n2))) + 1;
  int tmp=n2;
  int temp=n1;
  int tmp1 =n1;
  int tmp2 =n2;
  int flag1=0;
  int flag2=0;
  int d11;
  int d12;
  int d21;
  int d22;
  if(length1!=length2)
    return 0;
  for(int i=0;i<length1;i++){
    d11=n1%10;
    d21=tmp2%10;
    for(int j=0;j<length1;j++){
      d12=n2%10;
      d22=tmp1%10;
      if(d11==d12){
        flag1=1;
      }
      if(d21==d22)
        flag2=1;
      n2/=10;
      tmp1/=10;
    }
    if(flag1==0||flag2==0)
      return 0;
    flag1=0;
    flag2=0;
    n2=tmp;
    tmp1=temp;
    n1/=10;
    tmp2/=10;
  }
  return 1;
}
int main(){
  int i=1;
  while(1){
    if((floor(log10(abs(i))) + 1)!=(floor(log10(abs(i*6))) + 1)){
      i*=6;
    }
   else if(compare(i, i*2)&&compare(i, i*3)&&compare(i,i*4)&&compare(i, i*5)&&compare(i, i*6)){
      break;
    }
    i++;
  }
  printf("%d",i);
  return 0;
}
