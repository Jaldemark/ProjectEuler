#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

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
    for(int i=a->used;i<(int)a->size;i++){
      a->array[i]=0;
    }
  }
  a->array[a->used++] = element;
}
int main(){
  int sum=0;
  int tmp_leftover=0;
  int leftover = 0;
  Array a;
  init_array(&a, 1);
  insert_array(&a, 1);
  for(int i=1;i<=100;i++){
    for(int j=0;j<=(int)a.used+1;j++){
      if(a.array[j]*i+leftover>9){
        if(j>=(int)a.used){
          tmp_leftover = a.array[j]*i+leftover;
          insert_array(&a, (a.array[j]*i+leftover)%10);
        }
        else{
          tmp_leftover = a.array[j]*i+leftover;
          a.array[j]=(a.array[j]*i+leftover)%10;
        }
        leftover=(tmp_leftover-(tmp_leftover%10))/10;
        tmp_leftover=0;
      }
      else{
        a.array[j]=a.array[j]*i+leftover;
        leftover=0;
        tmp_leftover = 0;
      }
    }
  }
  printf("\n");
  for(int i=(int)a.used;i>=0;i--){
    sum += a.array[i];
    printf("%d",a.array[i]);
  }
  printf("sum: %d", sum);
  return 0;
}
