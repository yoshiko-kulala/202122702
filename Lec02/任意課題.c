#include <stdio.h>

int main() {
  //指定された手順
  int is_prime[100];
  for (int i=0;i<100;i++)is_prime[i]=1;
  is_prime[0]=0;

  //2以降の倍数の除去
  for(int i=2;i<100;i++){
    for(int j=i;j<100;j++){
      if(i*j>100)break;
      is_prime[i*j-1]=0;
    }
  }

  //is_prime[i]==1だった数字の出力
  for (int i=0;i<100;i++){
    if(is_prime[i]==1)printf("%d\n",i+1);
  }
  
  return 0;
}