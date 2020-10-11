#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
/*
Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O

Find the least value of n for which p(n) is divisible by one million.

*/
/*STUDY https://en.wikipedia.org/wiki/Partition_(number_theory)
1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565, 5604,
0, 1, 2, 3, 4, 5,  6,  7, ...
p(n) = p(n – 1)  + p(k – 2) – p(k – 5) – p(k – 7) + p(k – 12) + p(k – 15) – p(k – 22)…

where p(0) = 1 and p(n)  = 0 for n < 0.

f(k) = k(3k-1)/2
f(0) = 0(-1)/2=0
f(1) = 1(3*1-1)/2=1
f(-1) = -1((3*-1)-1)/2=2
f(2) = 2(3*2-1)/2=5
f(-2) = -2((3*-2)-1)/2=7
f(3) = 3(3*3-1)/2=12
f(4) = 4(3*4-1)/2=22

n is the value k goes towards
p(1)=p(1-1)=p(0)=1
p(2)=p(2-1)+p(0)=1+1=2
p(3)=p(2)+p(1)
p(4)=p(3)+p(2)=5
p(5)=p(4)+p(3)-p(0)=5+3-1=7
p(6)=p(5)+p(4)-p(1)=7+5-1=11
p(7)=p(6)+p(5)-p(2)-p(0)=11+7-2-1=15
*/
typedef struct{
  int* array;
  size_t used;
  size_t size;
}Array;

void init_array(Array *a){
  a->array = (int*)malloc(1);
  a->size = 1;
  a->used = 0;
}
void insert_array(Array *a, int element){
  if(a->used==a->size){
    a->size *=2;
    a->array= (int*)realloc(a->array, a->size*sizeof(int));
  }
  a->array[a->used++] = element;
}
int p(int n){

}
int main(){
  int pn=1;
  int prev_pn;
  int i=0;
  int sum =0;
  int k=1;
  Array a;
  init_array(&a);
  int val;
  while(val<100000){
    val=k*((3*k)-1)/2;
    insert_array(&a, val);
    val=(k*-1)*((3*(k*-1))-1)/2;
    insert_array(&a, val);
    k++;
  }
  while(pn%1000000!=0||pn==0){
    if(i==0){
      pn=1;
      sum+=pn;
      prev_pn=pn;
    }
    else{

    }
    i++;
    sum %=10000000;
  }

  return 0;
}
