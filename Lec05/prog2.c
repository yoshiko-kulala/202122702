#include<stdio.h>

//このスワップお気に入りです()
#define swap(type, a, b) do{b ^= a;a ^= b;b ^= a;} while(0)

int main(void)
{
  int na,nb;
  
  puts("二つの整数を入力せよ．");
  printf("整数Ａ:"); scanf("%d", &na);
  printf("整数Ｂ:"); scanf("%d", &nb);
  swap(int, na, nb);
  puts("\nＡとＢの値を交換");
  printf("整数Ａ=%d\n", na);
  printf("整数Ｂ=%d\n", nb);
  
  return (0);
}