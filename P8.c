#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){

  char number[1000]="73167176531330624919225119674426574742355349194934969835203127745063262395783180169848018694788518438586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772390713810515859307960866701724271218839987979087922749219016997208880937760657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824561786645835912456652947654568284891288314260769004224219022671055626321111109370544217506941658960408071984038509624554443629812309878799272442849091888458015616609791913387549920052406368991256071760588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  long long product = 1;
  long long highest_product = 1;
  for(int i=0;i<1000-13;i++){
    for(int j=0;j<13;j++){
      product *= number[i+j] - '0';
    }
    if(highest_product<product)
      highest_product = product;
    product = 1;
  }
  printf("%lld\n", highest_product);
  return 0;
}
