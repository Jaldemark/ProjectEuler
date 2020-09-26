#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isPalindrome(int d);
int main(){
  int product;
  int num1 = 100;
  int num2 = 100;
  int highest_palindrome=0;
  while(num2<1000){
    product = num1*num2;
    if(product == 906609){
      printf("%s\n", "fuck this");
    }
    if(isPalindrome(product)){
      if(product > highest_palindrome)
        highest_palindrome = product;
    }
    if(num1<1000){
      num1++;
    }
    else{
      num1=num2;
      num2++;
    }
  }
  printf("%d", highest_palindrome);
  return 0;
}
bool isPalindrome(int d){
  bool b = false;
  int len = floor(log10(abs(d))) + 1;
  int ar[len];
  for(int j=len;j>0;j--){
    ar[j-1]=d%10;
    d /= 10;
  }
  for(int i=0; i<(len/2);i++){
    if(ar[i]%10==ar[len-(i+1)]){
      b = true;
    }
    else{
      b=false;
      break;
    }
  }
  return b;
}
