#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

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
int binarySearch(Array *a, int l, int r, int x){
  if(r==0){
    return -1;
  }
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (a->array[mid] == x)
      return mid;
    if (a->array[mid] > x)
      return binarySearch(a,l, mid - 1, x);
    return binarySearch(a, mid + 1, r, x);
  }
  return -1;
}
int is_prime(int n){
  if(n==2||n==3||n==5){
    return 1;
  }
  if((n%2==0)||n%3==0||n%5==0)
    return 0;
  for(int i=3;i<=sqrt(n);i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
void generate_primes(Array *a, int upper_limit){
  for(int i=2;i<upper_limit;i+=2){
    if(is_prime(i)){
      insert_array(a,i);
    }
    if(i==2)
      i--;
  }
}
int main(){
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  Array a;
  int longest =0;
  int sum=0;
  int highest_prime=0;
  init_array(&a,2);
  generate_primes(&a,1000000);
  for(int i=0;i<sqrt((int)a.used);i++){//starting prime
    sum+=a.array[i];
    for(int j=i+1;j<(int)a.used/2;j++){
      sum += a.array[j];
      if(sum>=1000000)
        break;
      else if(binarySearch(&a, j,a.used, sum)!=-1&&longest<(j-i)){
        longest=(j-i);
        highest_prime=sum;
      }
    }
    sum=0;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("cpu time used: %.2f seconds\n", cpu_time_used);
  printf("sum=%d\n", highest_prime);
  printf("longest=%d\n", longest);
  return 0;
}
