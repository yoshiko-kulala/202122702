#include <stdio.h>
/*--- nx・nyが指すオブジェクトの値を交換 ---*/
void swap(int *nx, int *ny)
{
	int temp = *nx;
	*nx = *ny;
	*ny = temp;
}
/*--- *n1≦*n2≦*n3となるように並びかえる ---*/
void sort3(int *n1,int *n2,int *n3){
    if(*n1>*n2)swap(n1,n2);//1,2で比較、この時点でこの2つの大小関係は正しくなる
    if(*n2>*n3)swap(n2,n3);//同様に2,3で比較、この時交換の有無に関わらず、1,2より3が大きいことがわかる
    if(*n1>*n2)swap(n1,n2);//最後に交換の有無によって大小の分からない1,2を比較する
}

int main(void)
{
	int na,nb,nc;
	puts("三つの整数を入力してください。");
	printf("整数A:");	scanf("%d",&na);
	printf("整数B:");	scanf("%d",&nb);
	printf("整数C:");	scanf("%d",&nc);
	sort3(&na, &nb, &nc);
	
	puts("これらの値を昇順に並べかえました。");
	printf("整数Aは%dです。\n",na);
	printf("整数Bは%dです。\n",nb);
	printf("整数Cは%dです。\n",nc);
	return 0;
}