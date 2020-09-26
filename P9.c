#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/*

*/
int main(){
  int a=0;//333
  int b=0;//666
  int c=0;//
  for(a=0;a<333;a++){
    for(b=a+1;b<500;b++){
      c = sqrt(a*a+b*b);
      if((a+b+c)==1000 && (c*c==a*a+b*b)){
        printf("%d, %d, %d, %d\n", a*b*c,a,b,c);
        return 0;
      }
    }
  }
  return 0;
}
