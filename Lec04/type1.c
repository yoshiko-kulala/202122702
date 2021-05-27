/* 符号無し整数のビットを表示する */
#include <stdio.h>
/* 整数ｘ中のセットされたビット数を返す */
int count_bits(unsigned x)
{
	int count = 0;
	
	while (x){
		if(x & 1U) count++;
		x >>= 1;
	}
	return (count);
}
/* unsigned型のビット数を返す */
int int_bits(void)
{
	return (count_bits(~0U));
}
/* unsigned型のビット内容を表示 */
void print_bits(unsigned x)
{
    for(int i=int_bits()-1;i>-1;i--){//unsigned型の桁数(2進数での)分のループ
        int beki=1;
        for(int j=0;j<i;j++)beki=beki*2;//2のi乗を計算
		printf("%d",(x&beki)>0);//1ビットずつ評価
    }
}
int main(void)
{
	unsigned nx;
	printf("非負の整数を入力してください：");
	scanf("%u", &nx);
	printf("\n");
	
	print_bits(nx);
	putchar('\n');
	return (0);
}