#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
typedef struct{
  int* array;
  size_t used;
  size_t size;
}Array;

void init_array(Array *a, size_t init_size){
  a->array = (int*)malloc(init_size);
  a->size = init_size;
  a->used = 0;
}
void insert_array(Array *a, int element){
  if(a->used==a->size){
    a->size *=2;
    a->array= (int*)realloc(a->array, a->size*sizeof(int));
  }
  a->array[a->used++] = element;
}
void clear_array(Array *a){
  for(int i=0;i<a->used;i++){
    a->array[i]=0;
  }
  a->size=1;
  a->used=0;
}
void dec2bin(Array *a,int dec){
  int i =0;
  while(dec>0){
    insert_array(a, dec%2);
    dec =dec/2;
    i++;
  }
}
int isPalindromeDec(int d){
  int len = floor(log10(abs(d))) + 1;
  int ar[len];
  for(int j=len;j>0;j--){
    ar[j-1]=d%10;
    d /= 10;
  }
  for(int i=0; i<(len/2);i++){
    if(ar[i]%10!=ar[len-(i+1)]){
      return 0;
    }
  }
  return 1;
}
int isPalindromeBin(Array *a){
  printf("\n");
  for(int i=0; i<(a->used/2);i++){
    if(a->array[i]%10!=a->array[a->used-(i+1)]){
      return 0;
    }
  }
  return 1;
}
int main(){
  Array a;
  init_array(&a,2);
  int sum=0;
  for(int i=1;i<1000000;i++){
    if(isPalindromeDec(i)){
      dec2bin(&a,i);
      if(isPalindromeBin(&a)){
        printf("%d\n", i);
        sum+=i;
      }
      clear_array(&a);
    }
  }
  printf("%d", sum);
  return 0;
}
