#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>


int main(){
  int ar[15][15];
  int i,j,x;
  for (i=0;i<15;i++){
    for (j=0;j<15;j++){
      if (j<=i){
        scanf("%d",&x);
        ar[i][j]=x;
      }
      else
        ar[i][j]=0;
    }
  }
  printf("%d", ar[1][0]);
  int tmp[15][15];
  tmp[0][0]=ar[0][0];
  int highest;
  for(i=1;i<15;i++){                 //         [i-1][0]
    tmp[i][0]=tmp[i-1][0] + ar[i][0];//tmp  [i][0]   [i][i]
    printf("tmp: %d, ar: %d", tmp[i-1][0], ar[i][0]);
    tmp[i][i]=tmp[i-1][i-1] + ar[i][i];
    printf("---tmp: %d, ar: %d\n", tmp[i-1][i-1], ar[i][i]);
    for(j=1;j<i;j++){
      highest = (tmp[i-1][j-1]<tmp[i-1][j] ? tmp[i-1][j] : tmp[i-1][j-1]);
      tmp[i][j]=ar[i][j] + highest;
    }
  }
  int sum=0;
  for(i=0;i<15;i++){
    if(tmp[14][i]>sum){
      printf("%d\n", tmp[14][i]);
    }
  }
  return 0;
}
