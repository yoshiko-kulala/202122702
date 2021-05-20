#include <stdio.h>
/* 大きいほうの値を返す関数maxof */

int maxof(int na,int nb){
	if(na>nb)nb=na;//nbの方が小さければnbにnaを代入
	return nb;
}


int main(void){
	int na,nb;
	
	puts("二つの整数を入力してください。");
	printf("整数１：");
	scanf("%d",&na);
	printf("整数２：");
	scanf("%d",&nb);
	
	printf("大きいほうの値は%dです。\n",maxof(na,nb));
	
	return (0);
}