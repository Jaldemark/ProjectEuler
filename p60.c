#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime.
For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
*/
/*NOTES
Solution assumed the primes are below 10000, which it doesnt need to be. Plan was to make it work for 10000 first and then implement a dynamic increase in size but got lucky
that the first set found was the right one.
*/
typedef struct{
  int* array;
  int highest;
  size_t used;
  size_t size;
  int* concated_array;
  size_t concated_used;
  size_t concated_size;
  int* notprime_array;
  size_t notprime_used;
  size_t notprime_size;
}Array;

void init_array(Array *a, size_t init_size){
  a->array = (int*)malloc(init_size);
  a->size = init_size;
  a->used = 0;
  a->concated_array = (int*)malloc(init_size);
  a->concated_size = init_size;
  a->concated_used = 0;
  a->notprime_array = (int*)malloc(init_size);
  a->notprime_size = init_size;
  a->notprime_used = 0;
  a->highest=0;
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
void insert_arrayP(Array *a, int element){
  if(a->notprime_used==a->notprime_size){
    a->notprime_size *=2;
    a->notprime_array= (int*)realloc(a->notprime_array, a->notprime_size*sizeof(int));
  }
  a->notprime_array[a->notprime_used++] = element;
}
void insert_arrayC(Array *a, int element){
  if(a->concated_used==a->concated_size){
    a->concated_size *=2;
    a->concated_array= (int*)realloc(a->concated_array, a->concated_size*sizeof(int));
  }
  a->concated_array[a->concated_used++] = element;

}
int dup_concate(Array *a, int n){
  for(int i=0;i<(int)a->concated_used;i++){
    if(a->concated_array[i]==n)
      return 1;
  }
  return 0;
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
int binarySearchP(Array *a, int l, int r, int x){
  if(r==0){
    return -1;
  }
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (a->notprime_array[mid] == x)
      return mid;
    if (a->notprime_array[mid] > x)
      return binarySearchP(a,l, mid - 1, x);
    return binarySearchP(a, mid + 1, r, x);
  }
  return -1;
}
int is_prime(int n, Array *a){
  int prime =1;
  if(binarySearch(a, 0, a->used-1, n)==-1){
    if(n==3)
      return 1;
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
  return prime;
}
int is_primeK(int n, Array *a){
  int prime =1;
  if(binarySearch(a, 0, a->used-1, n)==-1){
    if(n==3)
      return 1;
    if((n%5==0&&n!=5)||n%2==0||n%3==0)
      return 0;
    for(int i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
        return 0;
      }
    }
  }
  return prime;
}
int is_primeC(Array *a,int n){
  int prime =1;
  if(dup_concate(a,n))
    return 1;
  if((binarySearchP(a, 0, a->notprime_used-1, n)!=-1))
    return 0;
  if((binarySearch(a, 0, a->used-1, n)==-1)){
    if(n==3)
      return 1;
    if((n%5==0&&n!=5)||n%2==0||n%3==0)
      return 0;
    for(int i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
        return 0;
      }
    }
  }
  if(!dup_concate(a,n)&&binarySearchP(a, 0, a->notprime_used-1, n)==-1)
    insert_arrayC(a,n);
  return prime;
}
int find_next_prime(int n, Array *a){
  while(1){
    n++;
    if(is_prime(n,a))
      break;
  }
  return n;
}
int concate(int n1, int n2){
  int length = floor(log10(abs(n2))) + 1;
  int tmp;
  n1*=pow(10,(length));
  tmp = n1+n2;
  return tmp;
}
/*
  p1p2 p1p3 p1p4 p1p5
  p2p1 p2p3 p2p4 p2p5
  p3p1 p3p2 p3p4 p3p5
  p4p1 p4p2 p4p3 p4p5
  p5p1 p5p2 p5p3 p5p4
*/
int is_concated(int p1,int p2,int p3,int p4,int p5, Array *a){
  int arr[5] ={p1,p2,p3,p4,p5};
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(i!=j){
        if(!is_primeC(a,concate(arr[i],arr[j]))){
          return 0;
        }
      }
    }
  }
  return 1;
}
int main(){
  int prime1=3;
  int prime2=3;
  int prime3=3;
  int prime4=3;
  int prime5=3;
  int i1,i2,i3,i4,i5;
  Array a;
  init_array(&a, 1);
  insert_array(&a,prime1);
  insert_array(&a,prime2);
  insert_array(&a,prime3);
  insert_array(&a,prime4);
  insert_array(&a,prime5);
  for(int i=0;i<10000;i++){
    if(!is_prime(i,&a)){
      insert_arrayP(&a,i);
    }
  }
  printf("%d\n", a.used);
  for(i1=0;i1<(int)a.used;i1++){
    prime1= a.array[i1];
    for(i2=0;i2<(int)a.used;i2++){
      prime2=a.array[i2];
      if(is_primeK(concate(prime1,prime2),&a)&&is_primeK(concate(prime2,prime1),&a)){
        for(i3=0;i3<(int)a.used;i3++){
          prime3=a.array[i3];
          if(is_primeK(concate(prime1,prime3),&a)&&is_primeK(concate(prime2,prime3),&a)&&is_primeK(concate(prime3,prime1),&a)&&is_primeK(concate(prime3,prime2),&a)){
            for(i4=0;i4<(int)a.used;i4++){
              prime4=a.array[i4];
              if(is_primeK(concate(prime1,prime4),&a)&&is_primeK(concate(prime2,prime4),&a)&&is_primeK(concate(prime3,prime4),&a)&& is_primeK(concate(prime4,prime1),&a)&&is_primeK(concate(prime4,prime2),&a)&&is_primeK(concate(prime4,prime3),&a)){
                for(i5=0;i5<(int)a.used;i5++){
                  prime5=a.array[i5];
                  if(is_concated(prime1,prime2,prime3,prime4,prime5,&a))
                    goto done;
                }
              }
            }
          }
        }
      }
    }
  }
  done:
    printf("%d %d %d %d %d\n", prime1,prime2,prime3,prime4,prime5);
    printf("sum: %d\n", prime1+prime2+prime3+prime4+prime5);
    printf("%d %d %d %d %d\n", i1,i2,i3,i4,i5);

  return 0;
}
