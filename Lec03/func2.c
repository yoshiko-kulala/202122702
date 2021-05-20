#include <stdio.h>
/*--- 五つの整数の最大値を返す関数max5 ----*/

int max5(int na,int nb,int nc,int nd,int ne){
    if(na<nb)na=nb;
    if(na<nc)na=nc;
    if(na<nd)na=nd;
    if(na<ne)na=ne;
    return na;
}  


int main(void){
	int na,nb,nc,nd,nf;
	
	puts("五つの整数を入力してください。");
	printf("整数１：");
	scanf("%d",&na);
	printf("整数２：");
	scanf("%d",&nb);
	printf("整数３：");
	scanf("%d",&nc);
	printf("整数４：");
	scanf("%d",&nd);
	printf("整数５：");
	scanf("%d",&nf);
	
	printf("最も大きい値は%dです。\n",max5(na,nb,nc,nd,nf));
	
	return (0);
}