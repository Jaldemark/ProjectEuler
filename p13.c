#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main(){
  FILE *fp;
  int sum[52] = {0};
  int current_number[50] = {0};
  int i, current_c;
  int counter = 0;
  int leftover=0;
  char c;
  fp = fopen("p13.txt", "r");
  if(fp==NULL){
    printf("Unable to open");
    return 1;
  }
  c = fgetc(fp);
  while(c!= EOF){
    current_c = c - '0';
    if(c=='\n'){
      for(int k=i-2;k>=0;k--){
        if((sum[k+2]+current_number[k]+leftover)>9){
          sum[k+2]=(sum[k+2]+current_number[k]+leftover)%10;
          leftover=1;
        }
        else{
          sum[k+2]=sum[k+2]+current_number[k]+leftover;
          leftover=0;
        }
      }
      if(leftover==1){
        sum[1]+=leftover;
        counter++;
        if(sum[1]==10){
          sum[0]++;
          sum[1]=0;
        }
      }
      leftover=0;
      i=0;
    }
    else{
      current_number[i]=current_c;
      i++;
    }
    c = fgetc(fp);
  }
  for(int j=0;j<10;j++){
    printf("%d", sum[j]);

  }
  return 0;
}
