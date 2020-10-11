#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.
*/
//eleven,twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
int main(){
  int singulars[9]={3,3,5,4,4,3,5,5,4};
  int tenths[10]={3,6,6,8,8,7,7,9,8,8};
  int tenths_over_10[8]={6,6,5,5,5,7,6,6};
  int hudreds[9]={10,10,12,11,11,10,12,12,11};
  int number_of_letters=0;
  int length;
  for(int i=1;i<1000;i++){
    int length = floor(log10(abs(i))) + 1;
    if(length==1){
      number_of_letters+=singulars[i];
    }
    else if(length==2){
      if(i<20){
        number_of_letters+=tenths[i%10];
      }
      else{
        if(i%10==0){
          number_of_letters+=tenths_over_10[(i/10)-2];
        }
        else{
          number_of_letters+=singulars[i%10-1]+tenths_over_10[(i/10)-2];
        }
      }
    }
    else{
      int tmp=(i%100);
      if(tmp<20&&tmp>=10){
        number_of_letters+=tenths[tmp%10];
      }
      else if(tmp>=20){
        if(tmp%10==0){
          number_of_letters+=tenths_over_10[(tmp/10)-2];
        }
        else{
          number_of_letters+=singulars[tmp%10-1]+tenths_over_10[(tmp/10)-2];
        }
      }
      else if(tmp<10)
        number_of_letters+=singulars[tmp];
      number_of_letters+=hudreds[(i/100)-1];
      if((i%100)!=0)
        number_of_letters+=3;
    }
  }
  printf("%d", number_of_letters+11);//11 for 1000
  return 0;
}
