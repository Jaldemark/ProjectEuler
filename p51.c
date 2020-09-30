#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers,
yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

YYY XXY XYX YXX
*/
int is_prime(int n){
  int prime =1;
  if((n%5==0&&n!=5)||n%2==0||n%3==0)
    return 0;
  for(int i=3;i<=n/2;i+=2){
    if(n%i==0){
      prime=0;
      break;
    }
  }
  return prime;
}
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
  int length = floor(log10(abs(element))) + 1;
  int tmp = element;
  a->used=length;
  if(a->used==a->size){
    a->size *=2;
    a->array= (int*)realloc(a->array, a->size*sizeof(int));
    for(int i=a->used;i<(int)a->size;i++){
      a->array[i]=0;
    }
  }
  for(int i=length-1;i>=0;i--){
    tmp = element%10;
    a->array[i]=tmp;
    if(element!=0)
      element/=10;
  }
}
int array_to_number(Array a, int length){
  int n=0;
  int factor;
  for(int i=0;i<length;i++){
    factor = pow(10,i);
    n += (factor*a.array[length-i-1]);
  }
  return n;
}
int contains(int n, int a[]){
  for(int i=0;i<8;i++){//prime_array is of size 8
    if(a[i]==n)
      return 1;
  }
  return 0;
}
int main(){
  int prime_counter=0;//max 8
  int length;
  int prime_array[8] = {0};
  Array a;
  init_array(&a, 8);
  int digit=100001;
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  while(1){
    if(is_prime(digit)){
      insert_array(&a,digit);
      length = floor(log10(abs(digit))) + 1;
      for(int i=0;i<length-1;i++){// 2
        for(int j=i+1;j<length;j++){
          for(int k=i+2;k<length;k++){
            for(int d=0;d<10;d++){
              insert_array(&a,digit);
              a.array[i]=d;
              a.array[j]=d;
              a.array[k]=d;
              if(is_prime(array_to_number(a, length)) && !contains(array_to_number(a, length),prime_array) && a.array[0]!=0){
                prime_array[prime_counter]=array_to_number(a, length);
                prime_counter++;
              }
            }
            if(prime_counter==8){
              end = clock();
              cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
              printf("cpu time used: %.2f seconds\n", cpu_time_used);
              for(int i=0;i<8;i++){//prime_array is of size 8
                printf("%d\n", prime_array[i]);
              }

              return 0;
            }
            for(int c=0;c<8;c++){
              prime_array[c]=0;
            }
            prime_counter=0;
          }
        }
      }
    }
    digit+=2;
  }
  return 0;
}
