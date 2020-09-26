#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
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

void add_operation_array(Array *a, int element){
  int temp;
  int j=(int)a->used-1;
  //for(int j=(int)a->used-1;j>=(int)(a->used-nDigits);j--){//4>(4-3)
  while(element>0){
    temp=(element%10);
    printf(" %d, %d\n", j,(temp));
    if(a->array[j]+(temp)>9){
        a->array[j] = (a->array[j]+temp)%10;
        if(j-1<0){
          insert_array(a, 1);
          int tmp = a->array[a->used-1];
          for(int k=a->used-1;k>=1;k--){
            a->array[k]=a->array[k-1];
          }
          a->array[0]=tmp;
          j++;
        }
        else{
          a->array[j-1]++;
        }
    }
    else{
      if(j<0){
        insert_array(a, temp);
        int tmp = a->array[a->used-1];
        for(int k=a->used-1;k>=1;k--){
          a->array[k]=a->array[k-1];
        }
        a->array[0]=tmp;
        j++;
      }
      else
        a->array[j] = (a->array[j]+(temp));
    }
    element /=10;
    j--;
  }
}
void multiplication_operation_array(Array *a, int element){
  int temp;
  int j=(int)a->used-1;
  int leftover=0;
  int tmp_leftover=0;
  int while_count=1;
  //for(int j=(int)a->used-1;j>=(int)(a->used-nDigits);j--){//4>(4-3)
  while(j>=0){
    temp=(element);
    printf(" %d, %d\n", j,(temp));
    if(a->array[j]*(temp)+leftover>9){
        tmp_leftover = a->array[j]*temp+leftover;
        a->array[j] = (a->array[j]*temp+leftover)%10;
        leftover=(tmp_leftover-((tmp_leftover)%10))/10;
        if(j-1<0){
          insert_array(a, leftover);
          int tmp = a->array[a->used-1];
          for(int k=a->used-1;k>=1;k--){
            a->array[k]=a->array[k-1];
          }
          a->array[0]=tmp;
        }
        else{
          while(j-while_count>=0 || (a->array[j-while_count]+leftover)>9){
            a->array[j-while_count]+=leftover;
            leftover= (a->array[j-while_count]+leftover)%10;
            while_count++;
          }
        }
    }
    else{
      if(j<0){
        insert_array(a, temp);
        int tmp = a->array[a->used-1];
        for(int k=a->used-1;k>=1;k--){
          a->array[k]=a->array[k-1];
        }
        a->array[0]=tmp;
      }
      else
        a->array[j] = (a->array[j]*(temp)+leftover);
      leftover=0;
    }
    printf("leftover: %d\n", leftover);
    j--;
  }
}
int isFull(Array *a){
  if(a->size==a->used){
    return 1;
  }
  return 0;
}
int main(){
  FILE *fp;
  fp = fopen("p022_names.txt", "r");
  int c;
  c = fgetc(fp);
  char *name;
  Array a;
  init_array(&a,4);
  insert_array(&a, 1);
  insert_array(&a, 2);
  insert_array(&a, 3);
  insert_array(&a, 4);
  insert_array(&a, 5);
  printf("div: %d\n",1/10);
  for(int i=0;i<(int)a.used;i++){
    printf("%d ",a.array[i]);
  }
  int e = 101;
  multiplication_operation_array(&a,e);
  printf("\n");
  for(int i=0;i<(int)a.used;i++){
    printf("%d ",a.array[i]);
  }
  return 0;
}
