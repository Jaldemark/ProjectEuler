#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
*/
/*NOTES
7069^2 = 49970761 and is the last prime to raise to the second power
367^3  = 49430863 and is the last prime to raise to the third power
83^4   = 47458321 and is the last prime to raise to the fourth power
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
void insert_ordered(Array *a, int element){
  if(a->used==a->size){
    a->size *=2;
    a->array= (int*)realloc(a->array, a->size*sizeof(int));
  }
  int i;
  for (i=a->used-1;(i>=0&&a->array[i]>element);i--){
    a->array[i+1] = a->array[i];
  }
  a->array[i+1] = element;
  a->used++;
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
  int pof2;
  int pof3;
  int pof4;
  int count=0;
  init_array(&a,2);
  init_array(&b,2);
  for(int i=1;i<=7069;i++){
    is_prime(i,&a);
  }
  int length = (int)a.used;
  for(int k=2;k<=83;k+=2){
    printf("%d\n", k);
    pof4=pow(k,4);
    if(binarySearch(&a,0,length,k)!=-1){
      for(int j=2;j<=367;j+=2){
        pof3=pow(j,3);
        if((pof3+pof4)>=50000000)
          break;
        if(binarySearch(&a,0,length,j)!=-1){
          for(int i=2;i<=7069;i+=2){
            pof2=pow(i,2);
            if((pof2+pof3+pof4)>=50000000)
              break;
            if((binarySearch(&a,0,length,i)!=-1)&&(binarySearch(&b,0,b.used,(pof2+pof3+pof4))==-1)){
              count++;
              insert_ordered(&b,(pof2+pof3+pof4));
            }
            if(i==2)
              i--;
          }
        }
        if(j==2)
          j--;
      }
    }
    if(k==2)
      k--;
  }
  printf("%d\n", count);
}
