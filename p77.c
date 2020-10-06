#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?
*/
/*NOTES


*/
typedef struct{
  int* array;
  size_t used;
  size_t size;
  int highest;
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
  if(a->highest<element)
    a->highest=element;
}
void fill_array(Array *a, int element){
  for(int i=0;i<a->used;i++){
    a->array[i]=element;
  }
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
int is_prime(int n, Array *a){
  if(binarySearch(a, 0, a->used, n)==-1){
    if(n==3||n==2){
      if(a->highest<n)
        insert_array(a,n);
      return 1;
    }
    if((n%5==0&&n!=5)||n%2==0||n%3==0)
      return 0;
    for(int i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
        return 0;
      }
    }
    if(a->highest<n)
      insert_array(a,n);
  }
  return 1;
}
int main(){
  Array a;
  Array b;
  int number=1;
  int max =10;
  int primes;
  int count=0;
  int max_number;//to determine how many numbers need to be added to the sum
  int smallest_prime;
  int sum=0;
  int array_index=0;
  int b_init =0;
  init_array(&a,2);
  for(int i=2;i<=max;i+=2){
    is_prime(i,&a);
    if(i==2)
      i--;
  }
  init_array(&b,10);
  smallest_prime=a.array[0];
  for(int i=0;i<(int)a.used;i++){
    printf("%d\n", a.array[i]);
  }
  while(1){
    max_number=max/smallest_prime;
    primes=a.used;
    for(int i=max-1;i>=0;i++){
      if(is_prime(i,&a)){
         while(sum<=max||array_index<max_number){
          if(sum+i>max)
            sum += i;
          /*  while(sum<=max||array_index<max_number){
              sum += b.array[array_index];
              if(sum==max){
                count++;
                break;
              }
              array_index++;
            }*/
        }
      }
      sum=0;
    }
    printf("%d \n", count);
    if(count>=5)
      break;
    count=0;
  }
  return 0;
}
